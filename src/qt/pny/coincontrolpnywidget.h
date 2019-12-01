// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2019 The CryptoDev developers
// Copyright (c) 2019 The peony developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLPNYWIDGET_H
#define COINCONTROLPNYWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlPnyWidget;
}

class CoinControlPnyWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlPnyWidget(QWidget *parent = nullptr);
    ~CoinControlPnyWidget();

private:
    Ui::CoinControlPnyWidget *ui;
};

#endif // COINCONTROLPNYWIDGET_H
