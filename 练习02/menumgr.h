///======================================================================
///  Project:   Richer01
/// FileName:	menumgr.h
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#ifndef MENUMGR_H
#define MENUMGR_H

#include "global.h"

class Menu;
class AbsMenuFactory;

class MenuMgr
{
public:
    static MenuMgr* getMgr();
    static void      releaseMgr();
private:
    static MenuMgr* mgr;
private:
    MenuMgr();
    MenuMgr(const MenuMgr&);
    MenuMgr& operator=(const MenuMgr&);
public:
    ~MenuMgr();
    void setMenuFactory(AbsMenuFactory* pFac);
    void setCurMenu(int menuID);
    Menu* getMenu(int menuID);
    Menu* getCurMenu();
private:
    Menu* curMenu = nullptr;
    Menu* menus[MenuID::MENU_COUNT];
    AbsMenuFactory* fac = nullptr;
};

#endif // MENUMGR_H
