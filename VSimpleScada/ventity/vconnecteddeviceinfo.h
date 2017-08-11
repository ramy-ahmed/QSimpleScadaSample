#ifndef CONNECTEDDEVICEINFO_H
#define CONNECTEDDEVICEINFO_H

#include "vbaseprefentity.h"

#include "../vboardinfo.h"
#include "../vboardcontroller.h"
#include "../vdevice/vdeviceinfo.h"

#include <QList>
#include <QHostAddress>

class VConnectedDeviceInfo;

struct VDeviceConfig {
    QString			name;
    QString			domain;
    QString			host;
    QHostAddress	ip;
    QHostAddress	ipv6;
    QList<VBoardInfo*> boardList;
};

class VConnectedDeviceInfo : public VBasePrefEntity
{
public:
    static const QString tag_devices;
    static const QString tag_device;
    static const QString tag_device_name;
    static const QString tag_device_ip;
    static const QString tag_device_ip_v6;
    static const QString tag_device_host;
    static const QString tag_device_domain;
    //board tags
    static const QString tag_boards;
    static const QString tag_board;
    static const QString tag_object;
    static const QString tag_title;
    static const QString tag_show_background;//new
    static const QString tag_show_background_image;//new
    static const QString tag_show_marker;//new
    static const QString tag_background_image;//new
    static const QString tag_id;
    static const QString tag_is_dynamic;
    static const QString tag_geometry_x;
    static const QString tag_geometry_y;
    static const QString tag_geometry_width;
    static const QString tag_geometry_height;
    static const QString tag_axis_enabled;
    static const QString tag_axis_position;//new
    static const QString tag_axis_x;
    static const QString tag_axis_y;
    static const QString tag_axis_z;

public:
    VConnectedDeviceInfo(QObject *parent = 0);

    static QString formTag(QString tag, bool isClosing, bool newLine, int numOfTabs); //so if formTag("device", false, true, 1) the result will be "\t<device>"
    static QString formTagValue(QString tag, QString value, bool newLine, int numOfTabs);


    QList<VDeviceConfig *> connecteDeviceList;

    void initFromXml(const QByteArray &xmlData);

    void saveXmlToFile(const QString &filePath);
    static QString XMLFromDeviceInfo(QList<VDeviceInfo> deviceList, VBoardController *);
};

#endif // CONNECTEDDEVICEINFO_H