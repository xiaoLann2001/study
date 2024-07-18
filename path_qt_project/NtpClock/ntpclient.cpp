#include "ntpclient.h"

NtpClient::NtpClient(QObject *parent)
    : QObject(parent)
{
    udpsocket = new QUdpSocket(this);
    connect(udpsocket, &QUdpSocket::readyRead, this, &NtpClient::processPendingDatagrams);
}

void NtpClient::sendNtpRequest(const QString &server)
{
    NtpPacket packet;

    quint64 msecs = static_cast<quint64>(QDateTime::currentDateTime().toMSecsSinceEpoch());
    quint64 t1 = msecs / 1000 + 2208988800ULL;
    t1 = (t1 << 32) | ((msecs % 1000) * (1ULL << 32) / 1000);     // timestamp
    t1 = qToBigEndian(t1);

    packet.setTransmitTimestamp(t1);                            // fill current time to t4

    QByteArray datagram(reinterpret_cast<char*>(&packet), sizeof(NtpPacket));
    udpsocket->writeDatagram(datagram, QHostAddress(server), 123);
}

void NtpClient::processPendingDatagrams()
{
    while (udpsocket->hasPendingDatagrams()) {
        // timestamp when received
        quint64 msecs = static_cast<quint64>(QDateTime::currentDateTime().toMSecsSinceEpoch());

        QByteArray datagram;
        datagram.resize(static_cast<int>(udpsocket->pendingDatagramSize()));
        udpsocket->readDatagram(datagram.data(), datagram.size());

        // process Ntp response
        NtpPacket *response = reinterpret_cast<NtpPacket*>(datagram.data());

        // time stamp
        quint64 t1 = qFromBigEndian(response->originateTimestamp);
        quint64 t2 = qFromBigEndian(response->receiveTimestamp);
        quint64 t3 = qFromBigEndian(response->transmitTimestamp);
        quint64 t4 = ((msecs / 1000 + 2208988800ULL) << 32) | ((msecs % 1000) * (1ULL << 32) / 1000);

        // delay and offset
        quint64 delay = (t4 - t1) - (t3 - t2);
        qint64 offset = ((static_cast<qint64>(t2) - static_cast<qint64>(t1)) +
                         (static_cast<qint64>(t3) - static_cast<qint64>(t4))) / 2;
        qint64 secoffset = offset >> 32;
        qint64 msecoffset = ((offset & 0xFFFFFFFFLL) * (1000LL)) >> 32;

        emit timeReceived(secoffset, msecoffset);

        if (DEBUG) {
            qDebug() << "originateTimestamp: " << t1;
            qDebug() << "receiveTimestamp: " << t2;
            qDebug() << "transmitTimestamp: " << t3;
            qDebug() << "destinationTimestamp: " << t4;
            qDebug() << "localClockOffset: " << offset;
            qDebug() << "secondsOffset: " << secoffset;
            qDebug() << "fractionOffset: " << msecoffset;
            qDebug() << "Round trip delay:" << ((delay * 1000) >> 32) << "ms";
            qDebug() << "Local clock offset:" << (secoffset * 1000 + msecoffset) << "ms";
        }
    }
}

