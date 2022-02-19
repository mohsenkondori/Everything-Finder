/*******************************************
**       Mohsen Abdollahzadeh Kondori     **
**       Email: MohsenKondori@yahoo.com   **
********************************************/

#include "files_model.h"

FilesModel::FilesModel(QObject *parent) : QAbstractListModel(parent)
{
}

int FilesModel::rowCount(const QModelIndex &) const
{
    return _files.count();
}

QVariant FilesModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < rowCount())
        switch (role) {
        case FileNameRole: return _files.at(index.row()).fileName;
        case PathRole: return _files.at(index.row()).path;
        case SizeRole: return _files.at(index.row()).size;
        default: return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> FilesModel::roleNames() const
{
    static const QHash<int, QByteArray> roles {
        { FileNameRole, "fileName" },
        { PathRole, "path" },
        { SizeRole, "size" }
    };
    return roles;
}

QVariantMap FilesModel::get(int row) const
{
    const File files = _files.value(row);
    return { {"fileName", files.fileName}, {"path", files.path}, {"size", files.size}};
}

void FilesModel::append(const QString &fileName, const QString &path, const QString &size)
{
    int row = 0;
    while (row < _files.count() && fileName > _files.at(row).fileName)
        ++row;
    beginInsertRows(QModelIndex(), row, row);
    _files.insert(row, {fileName, path, size});
    endInsertRows();
}

void FilesModel::removeAll()
{
    beginRemoveRows(QModelIndex(), 0, _files.count());
    _files.clear();
    endRemoveRows();
}
