#include <QApplication>
#include <QSlider>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

class Circle : public QWidget
{
public:
    Circle() = default;
    Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void changeColor(const int value);

private:
    QPixmap redCirclePixmap;
    QPixmap greenCirclePixmap;
    QPixmap yellowCirclePixmap;
    QPixmap currentCirclePixmap;
};



Circle::Circle(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    greenCirclePixmap   = QPixmap("D:\\Learning\\36_1_task_Qt_Circle\\circle_green.png");
    yellowCirclePixmap  = QPixmap("D:\\Learning\\36_1_task_Qt_Circle\\circle_yellow.png");
    redCirclePixmap     = QPixmap("D:\\Learning\\36_1_task_Qt_Circle\\circle_red.png");
    currentCirclePixmap = greenCirclePixmap;

    setGeometry(currentCirclePixmap.rect());
}



void Circle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), currentCirclePixmap);
}



QSize Circle::sizeHint() const
{
    return QSize(300, 300);
}



QSize Circle::minimumSizeHint() const
{
    return sizeHint();
}



void Circle::changeColor(const int value)
{
    if (value >= 0 && value <= 33)
        currentCirclePixmap = greenCirclePixmap;
    else if (value <= 66)
        currentCirclePixmap = yellowCirclePixmap;
    else 
        currentCirclePixmap = redCirclePixmap;

    update();
}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->resize(300, 400);
    window->move(1000, 500);

    auto *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);
    
    Circle *circle = new Circle(window);

    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, circle, [slider, circle]() 
        {
            int value = slider->value();
            circle->changeColor(value);
        });
    
    window->show();
    return app.exec();
}