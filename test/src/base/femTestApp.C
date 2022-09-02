//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "femTestApp.h"
#include "femApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
femTestApp::validParams()
{
  InputParameters params = femApp::validParams();
  return params;
}

femTestApp::femTestApp(InputParameters parameters) : MooseApp(parameters)
{
  femTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

femTestApp::~femTestApp() {}

void
femTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  femApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"femTestApp"});
    Registry::registerActionsTo(af, {"femTestApp"});
  }
}

void
femTestApp::registerApps()
{
  registerApp(femApp);
  registerApp(femTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
femTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  femTestApp::registerAll(f, af, s);
}
extern "C" void
femTestApp__registerApps()
{
  femTestApp::registerApps();
}
