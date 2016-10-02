#include "TransactionInfo.h"
#include "WalletManager.h"

#include <QDateTime>

TransactionInfo::Direction TransactionInfo::direction() const
{
    return static_cast<Direction>(m_pimpl->direction());
}

bool TransactionInfo::isPending() const
{
    return m_pimpl->isPending();
}

bool TransactionInfo::isFailed() const
{
    return m_pimpl->isFailed();
}


QString TransactionInfo::amount() const
{
    return WalletManager::instance()->displayAmount(m_pimpl->amount());
}

QString TransactionInfo::fee() const
{
    return WalletManager::instance()->displayAmount(m_pimpl->fee());
}

quint64 TransactionInfo::blockHeight() const
{
    return m_pimpl->blockHeight();
}

QString TransactionInfo::hash() const
{
    return QString::fromStdString(m_pimpl->hash());
}

QString TransactionInfo::timestamp()
{
    QString result = QDateTime::fromTime_t(m_pimpl->timestamp()).toString(Qt::ISODate);
    return result;
}

QString TransactionInfo::paymentId()
{
    return QString::fromStdString(m_pimpl->paymentId());
}

TransactionInfo::TransactionInfo(Bitmonero::TransactionInfo *pimpl, QObject *parent)
    : QObject(parent), m_pimpl(pimpl)
{

}
