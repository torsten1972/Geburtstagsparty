#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <QDate>
#include <QDateTime>




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

void writeUnitXml()
{
	QTime time;
	QDate date;
	QString strTime;
	QString strDate;


	time = QTime::currentTime();
	strTime = time.toString(Qt::TextDate);

	QDateTime asd(QDateTime::currentDateTime());
	uint unixTime = asd.toTime_t();

	date = QDate::currentDate();
	strDate = asd.toString("yyyy-mm-ddThh:mm:ss");

	QFile file(qApp->applicationDirPath()+ "/" + "test.xml");
	if(file.open(QIODevice::WriteOnly | QIODevice::Text)== true)
	{


		file.write("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
		file.write("<testsuites>\n");
		file.write("  <testsuite name=\"INT | Finanzieren - Smoketests\" tests=\"10\" failures=\"1\" skipped=\"1\" time=\"" +QByteArray::number(unixTime) + "\" timestamp=\"" + strDate.toLatin1()+ "\" id=\"39f13ba7-6820-d6dc-8165-76fbcceabc7e\" log=\"\">\n");
		file.write("	<testcase name=\"Finanzieren Smoketests - Grundstück erfassen\" time=\"" +QByteArray::number(unixTime) + "\" timestamp=\"" + strDate.toLatin1()+ ".6008759+01:00\" log=\"+ Passed Finanzieren Smoketests - Grundstück erfassen&#xD;&#xA;…\" />\n");
		file.write("	<testcase name=\"Finanzieren Smoketests - Versicherung erfassen\" time=\"93.8767338\" timestamp=\"" + strDate.toLatin1()+ ".9749463+01:00\" log=\"+ Passed Finanzieren Smoketests - Versicherung erfassen&#xD;&#xA;…\" />\n");
		file.write("	<testcase name=\"Finanzieren Smoketests - Finanzierung zusammenstellen\" time=\"143.0023053\" timestamp=\"" + strDate.toLatin1()+ ".3683063+01:00\" log=\"+ Failed Finanzieren Smoketests - Finanzierung zusammenstellen&#xD;&#xA;…\" />\n");
		file.write("	<testcase name=\"Finanzieren Smoketests - Kreditportfolio überprüfen\" time=\"\" timestamp=\"\">\n");
		file.write("	<skipped />\n");
		file.write("	</testcase>\n");
		file.write("  </testsuite>\n");
		file.write("</testsuites>\n");
		file.close();
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
	writeUnitXml();
	return 0;
}
