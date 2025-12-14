
#pragma once


namespace Core 
{
  class Layer
  {
    public:
    virtual void onRun();
    virtual void onCreate();
    //virtual void onUpdate();
    //virtual void fstime();
    ~Layer()
    {
      
    }
  };
}
