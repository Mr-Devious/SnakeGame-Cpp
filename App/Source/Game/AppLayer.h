#pragma once
#include "Layer.h"

namespace App
{
  
  
  class AppLayer : public Core::Layer
  {
public:
    virtual void onRun();
    virtual void onCreate();
  };
}
