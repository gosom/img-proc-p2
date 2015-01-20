#ifndef CYLINDERANAMORPHOSIS_H
#define CYLINDERANAMORPHOSIS_H
#include <qimage.h>

class CylinderAnamorphosis
{
public:
    CylinderAnamorphosis();
    CylinderAnamorphosis(QImage img, int _rmin);
    ~CylinderAnamorphosis();

    void setImage(QImage img){ _img = img; }

    QImage get_anamorphosis();

private:
    QImage _img;
    double centerX, centerY;
    double radius;
    int rmin;
};

#endif // CYLINDERANAMORPHOSIS_H
