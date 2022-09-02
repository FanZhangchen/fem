#include "femApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
femApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

femApp::femApp(InputParameters parameters) : MooseApp(parameters)
{
  femApp::registerAll(_factory, _action_factory, _syntax);
}

femApp::~femApp() {}

void
femApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"femApp"});
  Registry::registerActionsTo(af, {"femApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
femApp::registerApps()
{
  registerApp(femApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
femApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  femApp::registerAll(f, af, s);
}
extern "C" void
femApp__registerApps()
{
  femApp::registerApps();
}
