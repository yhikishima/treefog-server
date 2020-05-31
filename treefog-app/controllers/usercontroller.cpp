#include "usercontroller.h"
#include "user.h"


void UserController::index()
{
    auto userList = User::getAllJson();
    renderJson(userList);
}

void UserController::show(const QString &id)
{
    auto user = User::get(id.toInt());
    renderJson(user.toVariantMap());
}

void UserController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto user = httpRequest().formItems("user");
        auto model = User::create(user);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(user);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void UserController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = User::get(id.toInt());
        if (!model.isNull()) {
            session().insert("user_lockRevision", model.lockRevision());
            auto user = model.toVariantMap();
            texport(user);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("user_lockRevision").toInt();
        auto model = User::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto user = httpRequest().formItems("user");
        model.setProperties(user);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(user);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void UserController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto user = User::get(id.toInt());
    user.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(UserController)
