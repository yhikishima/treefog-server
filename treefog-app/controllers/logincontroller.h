#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT LoginController : public ApplicationController
{
    Q_OBJECT
public:
    LoginController() : ApplicationController() {}

public slots:
    void index();
    void create();
};

#endif // LOGINCONTROLLER_H
