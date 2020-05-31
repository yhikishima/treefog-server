#ifndef USER_H
#define USER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class UserObject;
class QJsonArray;


class T_MODEL_EXPORT User : public TAbstractModel
{
public:
    User();
    User(const User &other);
    User(const UserObject &object);
    ~User();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString password() const;
    void setPassword(const QString &password);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    User &operator=(const User &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static User create(const QString &name, const QString &password);
    static User create(const QVariantMap &values);
    static User get(int id);
    static User get(const QString &name, const QString &password);
    static int count();
    static QList<User> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<UserObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const User &model);
    friend QDataStream &operator>>(QDataStream &ds, User &model);
};

Q_DECLARE_METATYPE(User)
Q_DECLARE_METATYPE(QList<User>)

#endif // USER_H
