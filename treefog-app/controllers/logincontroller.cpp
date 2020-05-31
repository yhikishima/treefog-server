#include "logincontroller.h"
#include "user.h"

void LoginController::index()
{
    QString name = httpRequest().queryItemValue("name");
    QString password = httpRequest().queryItemValue("password");

    auto user = User::get(name, password);
    renderJson(user.toVariantMap());
}

void LoginController::create()
{
    QString name = httpRequest().queryItemValue("name");
    QString password = httpRequest().queryItemValue("password");

    auto modelUser = httpRequest().formItems("user");
    auto model = User::create(name, password);

    if (!model.isNull()) {
        QString notice = "Created successfully.";
        renderJson(model.toVariantMap());
    } else {
        QString error = "Failed to create.";
        renderJson(model.toVariantMap());
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(LoginController)
