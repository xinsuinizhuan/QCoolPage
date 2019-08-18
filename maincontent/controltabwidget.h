﻿#ifndef CONTROLTABWIDGET_H
#define CONTROLTABWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "globaldef.hpp"
#include "control/bannawidget.h"

namespace Ui {
class ControlTabWidget;
}
typedef struct TabWidgetData
{
    QWidget *currentWidget;
    QString currentTabText;
}TabWidgetData;

using MapWidget = QMap<WidgetTabType, TabWidgetData>;

class ControlTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlTabWidget(QWidget *parent = 0);
    ~ControlTabWidget();

signals:
    void sendShowIndex(WidgetTabType);

private slots:
    void closeNowTab(int index);
    void receiveShowCurrentTab(WidgetTabType widgetTabType);
    void on_tabWidgetControl_tabBarClicked(int index);

private:
    Ui::ControlTabWidget *ui;
    MapWidget mapTabWidget;
    void initValue();
};

#endif // CONTROLTABWIDGET_H