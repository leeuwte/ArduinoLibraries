/*
 *
 * Switch
 *
 * Modified version of Albert van Dalen's Switch Library
 * http://www.avdweb.nl/arduino/hardware-interfacing/simple-switch-debouncer.html
 *
 */

#ifndef SWITCH_H
#define SWITCH_H

class Switch
{
  public:
    //  Switch::Switch(byte _pin, byte PinMode, bool polarity, int debounceDelay, int longPressDelay, int doubleClickDelay):

    Switch(int pin);
    //  Switch(int _pin, int PinMode, bool polarity, int debounceDelay=50, int longPressDelay=400, int doubleClickDelay=250);

    bool poll(); // Returns 1 if switched
    bool switched(); // will be refreshed by poll()
    bool on();
    bool pushed(); // will be refreshed by poll()
    bool released(); // will be refreshed by poll()
    bool longPress(); // will be refreshed by poll()
    bool doubleClick(); // will be refreshed by poll()

    unsigned long _switchedTime, pushedTime;

  private:
    int pin;
    int debounceDelay, longPressDelay, doubleClickDelay;
    bool polarity;
    bool level, _switched, _longPress, longPressLatch, _doubleClick;
};

#endif
