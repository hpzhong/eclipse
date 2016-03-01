#include <QApplication>
#include <QLabel>

int colorMain(int argc, char **argv)
{
	QApplication app(argc, argv);
	QLabel *label = new QLabel("<h2><i>Hello </i><font color=red>Qt!</font></h2>");
	label->show();
	return app.exec();
}
