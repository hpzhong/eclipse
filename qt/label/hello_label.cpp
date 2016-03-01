#include <QApplication>
#include <QLabel>

int helloMain(int argc, char **argv)
{
	QApplication app(argc, argv);
	QLabel *label = new QLabel("Hello Qt");
	label->show();
	return app.exec();
}
