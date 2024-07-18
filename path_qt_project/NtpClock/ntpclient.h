#ifndef NTPCLIENT_H
#define NTPCLIENT_H

#include "global.h"
#include <QtEndian>

class NtpClient : public QObject
{
    Q_OBJECT

public:
    struct NtpPacket {
        quint8 li_vn_mode;
        quint8 stratum;
        quint8 poll;
        quint8 precision;
        quint32 rootDelay;
        quint32 rootDispersion;
        quint32 referenceIdentifier;
        quint64 referenceTimestamp;     // t1
        quint64 originateTimestamp;     // t2
        quint64 receiveTimestamp;       // t3
        quint64 transmitTimestamp;      // t4

        NtpPacket() {
            memset(this, 0, sizeof(NtpPacket));
            li_vn_mode = (0 << 6) | (3 << 3) | (3);  // LI = 0, VN = 4, Mode = 3 (Client)
            stratum = 0;
            poll = 6;
            precision = -20;
        }

        void setTransmitTimestamp(quint64 timestamp) {
            transmitTimestamp = timestamp;
            if (DEBUG)
                qDebug() << "transmitTimestamp: " << qFromBigEndian(transmitTimestamp);
        }
    };

    explicit NtpClient(QObject *parent = nullptr);
    void sendNtpRequest(const QString &server);

signals:
    void timeReceived(qint64 secoffset, qint64 msecoffset);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket *udpsocket;
    QHostAddress serverAddress;
};

#endif // NTPCLIENT_H
