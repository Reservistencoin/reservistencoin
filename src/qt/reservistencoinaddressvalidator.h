// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RESERVISTENCOIN_QT_RESERVISTENCOINADDRESSVALIDATOR_H
#define RESERVISTENCOIN_QT_RESERVISTENCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ReservistenCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ReservistenCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** ReservistenCoin address widget validator, checks for a valid reservistencoin address.
 */
class ReservistenCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ReservistenCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // RESERVISTENCOIN_QT_RESERVISTENCOINADDRESSVALIDATOR_H
