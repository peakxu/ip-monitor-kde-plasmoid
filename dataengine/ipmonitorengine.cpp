#include "ipmonitorengine.h"

#include <QNetworkInterface>

namespace
{
    static const int PollingInterval = 3000;
    static const QString DefaultText = "Not available";
}

IpMonitorEngine::IpMonitorEngine(QObject* parent, const QVariantList& args)
    : Plasma::DataEngine(parent, args)
{
    Q_UNUSED(args);
    setMinimumPollingInterval(PollingInterval);

    foreach(QNetworkInterface iface, QNetworkInterface::allInterfaces())
        updateSourceEvent(iface.name());
}

bool IpMonitorEngine::updateSourceEvent(const QString &source)
{
    QNetworkInterface iface = QNetworkInterface::interfaceFromName(source);
    if (!iface.isValid())
        return false;
    if (source == "lo")
        return true;

    QString address;
    QList<QNetworkAddressEntry> addrs = iface.addressEntries();
    if (addrs.size() > 0)
    {
        QHostAddress addr = addrs.at(0).ip();
        if (addr.protocol() == QAbstractSocket::IPv4Protocol)
            address = addr.toString();
        else
            address = DefaultText;
    }
    else
        address = DefaultText;

    setData(iface.name(), "Name", iface.humanReadableName());
    setData(iface.name(), "Address", address);
    return true;
}

#include "ipmonitorengine.moc"
