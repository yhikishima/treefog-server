#include <QtCore>
#include <TreeFrogView>
#include "user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_saveView : public TActionView
{
  Q_OBJECT
public:
  user_saveView() : TActionView() { }
  QString toString();
};

QString user_saveView::toString()
{
  responsebody.reserve(1607);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, user);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing User</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", user["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"user[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"user[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["name"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Password<br /><input type=\"text\" name=\"user[password]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["password"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", user["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(user_saveView)

#include "user_saveView.moc"
