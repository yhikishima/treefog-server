#include <TreeFrogModel>
#include "user.h"
#include "sqlobjects/userobject.h"

User::User() :
    TAbstractModel(),
    d(new UserObject())
{
    // set the initial parameters
}

User::User(const User &other) :
    TAbstractModel(),
    d(other.d)
{ }

User::User(const UserObject &object) :
    TAbstractModel(),
    d(new UserObject(object))
{ }

User::~User()
{
    // If the reference count becomes 0,
    // the shared data object 'UserObject' is deleted.
}

int User::id() const
{
    return d->id;
}

QString User::name() const
{
    return d->name;
}

void User::setName(const QString &name)
{
    d->name = name;
}

QString User::password() const
{
    return d->password;
}

void User::setPassword(const QString &password)
{
    d->password = password;
}

QDateTime User::createdAt() const
{
    return d->created_at;
}

QDateTime User::updatedAt() const
{
    return d->updated_at;
}

User &User::operator=(const User &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

User User::create(const QString &name, const QString &password)
{
    UserObject obj;
    obj.name = name;
    obj.password = password;
    if (!obj.create()) {
        return User();
    }
    return User(obj);
}

User User::create(const QVariantMap &values)
{
    User model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

User User::get(const QString &name, const QString &password)
{
    UserObject obj;
    obj.name = name;
    obj.password = password;
    return User(obj);
}

User User::get(int id)
{
    TSqlORMapper<UserObject> mapper;
    return User(mapper.findByPrimaryKey(id));
}

int User::count()
{
    TSqlORMapper<UserObject> mapper;
    return mapper.findCount();
}

QList<User> User::getAll()
{
    return tfGetModelListByCriteria<User, UserObject>(TCriteria());
}

QJsonArray User::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<UserObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<UserObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(User(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *User::modelData()
{
    return d.data();
}

const TModelObject *User::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const User &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, User &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(User)
