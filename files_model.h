#ifndef FILESMODEL_H
#define FILESMODEL_H

#include <QAbstractListModel>

class FilesModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum FileRole {
        FileNameRole = Qt::DisplayRole,
        PathRole = Qt::UserRole,
        SizeRole
    };
    Q_ENUM(FileRole)

    FilesModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const QString &fileName, const QString &path, const QString  &size);
    Q_INVOKABLE void removeAll();

private:
    struct File {
        QString fileName;
        QString path;
        QString size;
    };

    QList<File> _files;
};

#endif // FILESMODEL_H
