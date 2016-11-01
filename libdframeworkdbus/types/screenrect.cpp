#include "screenrect.h"

ScreenRect::ScreenRect()
    : x(0),
      y(0),
      w(0),
      h(0)
{

}

QDebug operator<<(QDebug debug, const ScreenRect &rect)
{
    debug << QString("ScreenRect(%1, %2, %3, %4)").arg(rect.x)
                                                    .arg(rect.y)
                                                    .arg(rect.w)
                                                    .arg(rect.h);

    return debug;
}

ScreenRect::operator QRect() const
{
    return QRect(x, y, w, h);
}

QDBusArgument &operator<<(QDBusArgument &arg, const ScreenRect &rect)
{
    arg.beginStructure();
    arg << rect.x << rect.y << rect.w << rect.h;
    arg.endStructure();

    return arg;
}

const QDBusArgument &operator>>(const QDBusArgument &arg, ScreenRect &rect)
{
    arg.beginStructure();
    arg >> rect.x >> rect.y >> rect.w >> rect.h;
    arg.endStructure();

    return arg;
}
