QT += widgets qml quick quickcontrols2

requires(qtConfig(filedialog))

HEADERS       = \
                files_model.h \
                t_finder.h
SOURCES       = main.cpp \
                files_model.cpp \
                t_finder.cpp

# install
INSTALLS += target

DISTFILES += \
    qml\AppButton.qml \
    qml\AppLabel.qml \
    qml\AppTextField.qml \
    qml\Backend/FilesModel.qml \
    qml\FilesDelegate.ui.qml \
    qml\FilesView.ui.qml \
    MainView.qml \
    qml\SectionDelegate.ui.qml

OTHER_FILES += \
    Backend/*.qml

RESOURCES += \
    AppSrc.qrc
