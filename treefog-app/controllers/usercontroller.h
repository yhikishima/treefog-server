#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UserController : public ApplicationController
{
    Q_OBJECT
public:
    UserController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // USERCONTROLLER_H
