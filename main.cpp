#include <QCoreApplication>
#include <QTextStream>
#include <QFile>




void fileout(int para)
{
	QString filename = "";
	QString strline;


	switch(para)
	{
		case 1:
			filename = "testpass.txt";
			break;
		case 2:
			filename = "testfail.txt";
			break;
	}

	QFile file(qApp->applicationDirPath()+ "/" + filename);
	if(file.exists())
	{
		if(file.open(QIODevice::ReadOnly | QIODevice::Text)== true)
		{
			while(!file.atEnd())
			{
				QTextStream(stdout) << file.readLine();
			}
			file.close();
		}
		else
		{
			QTextStream(stdout) << "file can not open!" << endl;
		}
	}
	else
	{
		QTextStream(stdout) << "file not found!" << endl;
	}
}

int main(int argc, char *argv[])
{
	int iPara=0;
	QCoreApplication a(argc, argv);
	for ( int i = 0; i < argc ; ++i )
	{
		QTextStream(stdout) << argv[i] << endl;
		if(QString("testpara=1").compare(argv[i]) == 0)
		{
			iPara=1;
		}
		else if(QString("testpara=2").compare(argv[i]) == 0)
		{
			iPara=2;
		}

	}
	QTextStream(stdout) << "Hello World!" << endl;
	fileout(iPara);
	return 0;
}
