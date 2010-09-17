#include "KDSoapMessage.h"
#include "KDSoapMessage_p.h"
#include <QDebug>
#include <QVariant>

KDSoapMessage::KDSoapMessage()
    : d(new KDSoapMessageData)
{
}

KDSoapMessage::KDSoapMessage(const KDSoapMessage& other)
    : KDSoapValue(other), d(other.d)
{
}

KDSoapMessage &KDSoapMessage::operator =(const KDSoapMessage &other)
{
    KDSoapValue::operator=(other);
    d = other.d;
    return *this;
}

KDSoapMessage::~KDSoapMessage()
{
}

void KDSoapMessage::addArgument(const QString &argumentName, const QVariant& argumentValue, const QString& typeNameSpace, const QString& typeName)
{
    childValues().append(KDSoapValue(argumentName, argumentValue, typeNameSpace, typeName));
}

void KDSoapMessage::addArgument(const QString& argumentName, const KDSoapValueList& argumentValueList, const QString& typeNameSpace, const QString& typeName)
{
    KDSoapValue soapValue(argumentName, argumentValueList, typeNameSpace, typeName);
    childValues().append(soapValue);
}

KDSoapValueList& KDSoapMessage::arguments()
{
    return childValues();
}

const KDSoapValueList& KDSoapMessage::arguments() const
{
    return childValues();
}

QDebug operator <<(QDebug dbg, const KDSoapMessage &msg)
{
    return dbg << KDSoapValue(msg);
}

bool KDSoapMessage::isFault() const
{
    return d->isFault;
}

QString KDSoapMessage::faultAsString() const
{
    return QObject::tr("Fault code: %1\nFault description: %2 (%3)")
            .arg(childValues().child(QLatin1String("faultcode")).value().toString())
            .arg(childValues().child(QLatin1String("faultstring")).value().toString())
            .arg(childValues().child(QLatin1String("faultactor")).value().toString());
}

void KDSoapMessage::setFault(bool fault)
{
    d->isFault = fault;
}

KDSoapMessage::Use KDSoapMessage::use() const
{
    return d->use;
}

void KDSoapMessage::setUse(Use use)
{
    d->use = use;
}
