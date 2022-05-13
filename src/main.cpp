#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator, qtTranslator;
#if QT_VERSION > QT_VERSION_CHECK(6, 0, 0)
    const QString path(QLibraryInfo::path(QLibraryInfo::TranslationsPath));
#else
    const QString path(QLibraryInfo::location(QLibraryInfo::TranslationsPath));
#endif

    const QString lang(QLocale::system().name());

    // load translation for Qt
    if (qtTranslator.load(QStringLiteral("qt_") + lang, path))
        a.installTranslator(&qtTranslator);
    else if (qtTranslator.load(QStringLiteral("qt_") + lang, QStringLiteral("translations")))
        a.installTranslator(&qtTranslator);

    // try to load translation for current locale from resource file
    if (translator.load(QStringLiteral("RockPaperScissors_") + lang, QStringLiteral(":/i18n")))
        a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
