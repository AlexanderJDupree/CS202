/*
File: Main.java

Description: Main.java acts as the entry point for our application. Defines
             static methods for building and displaying the contents of the
             Event Manager 2-3-4 tree.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;

import com.user_interface.Interface;

public class Main {

    public static void main(String[] args) {
        intro();

        run();
    }

    public static void intro() {
        System.out.println(
            "========================================================================" +
            "\n" +
            "\n" +
            "\n" +
            "\n" +
            "\n                              Program 4" +
            "\n" +
            "\n" +
            "\n                      Author: Alexander DuPree" +
            "\n" +
            "\n" +
            "\n" +
            "=======================================================================\n");
        Interface.pause_console();
    }

    public static void run() {

        Exit exit = new Exit();
        Game_Manager manager = new Game_Manager();

        Menu_Item[] menu = new Menu_Item[] {
                manager,
                exit
        };

        do {
            Game_Manager.print_menu(menu);

            int choice = Interface.get_int("> ",1, menu.length);

            menu[choice - 1].action();
        } while (!exit.exit());
    }

}
