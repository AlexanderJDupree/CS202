/*
File: Game_Manager.java

Description: The game manager class acts as the UI for the client and manages the use
             of the event_manager and player_history objects for each game. The game
             manager defines methods for reading/evaluating user input and printing
             out interactable menus to the console.

Author: Alexander DuPree

Assignment: Program 4

Date: 24 November 2018
 */

package com.program4;


import com.user_interface.Interface;

interface Menu_Item {
    void action();

    String option();
}

class Exit implements Menu_Item {
    private boolean exit = false;

    @Override
    public void action() {
        exit = !exit;
    }

    @Override
    public String option() {
        return "Exit";
    }

    public boolean exit() {
        return exit;
    }
}

class Next_Event implements Menu_Item {
    Event_Manager events;
    Player_History player;

    Next_Event(Event_Manager events, Player_History player) {
        this.events = events;
        this.player = player;
    }

    @Override
    public void action() {
        Event event = null;

        int i = 0;
        while(event == null) {
            event = events.find(player.points() + i++);
        }

        player.add(event, event.action());
    }

    @Override
    public String option() {
        return "Next Event";
    }
}


public class Game_Manager implements Menu_Item {

    boolean new_game = true;

    Event_Manager event_manager = build_event_manager();

    Player_History player_history = new Player_History();

    @Override
    public void action() {
        if(new_game) {
            new_game = !new_game;
        }

        run();
    }

    @Override
    public String option() {
        if (new_game) {
            return "New Game";
        }

        return "Continue";
    }

    public void new_game() {
        event_manager = build_event_manager();

        player_history.clear();
    }

    public void run() {

        Exit exit = new Exit();

        Menu_Item[] menu = new Menu_Item[] {
                new Next_Event(event_manager, player_history),
                exit
        };

        do {
            print_status();
            print_menu(menu);

            int choice = Interface.get_int("> ", 1, menu.length);

            menu[choice - 1].action();
        } while(!exit.exit() && player_history.points() >= 0);

        if(player_history.points() < 0) {
            print_game_summary();
            new_game = true;
            new_game();
        }
    }

    public void print_status() {
        System.out.println("Points: " + player_history.points());
    }

    private void print_game_summary() {
        System.out.println("Congratulations on beating the game!");
        System.out.println("\nHere's the summary of your progress: ");

        System.out.println("Total points: " + (player_history.points() + 1000));
        System.out.println();
        player_history.display_all();
    }

    public static void print_menu(Menu_Item[] menu) {

        System.out.println(
                "========================================================================");

        for(int i = 0; i < menu.length; ++i) {
            System.out.println((i + 1) + ".  " + menu[i].option());
        }

        System.out.println(
                "========================================================================");
    }

    // TODO the entire build process will be loaded from an external data file in the future.
    public static Event_Manager build_event_manager() {
        Event_Manager manager = new Event_Manager();

        manager.insert(0, new Decision(10,
                "Welcome to CS202 Decision analysis game! Ahead of you are two doors which do you choose?",
                "Left Door", "Right Door"));
        manager.insert(5, new Chance(5,
                "A coin is to be flipped? Type 1 for heads, 2 for tails", 1, 2));
        manager.insert(10, new Decision( 10,
               "You see a red door and a black door, which do you choose?",
               "Red Door", "Black Door"));
        manager.insert(15, new Riddle(5,
                "What weighs more a pound of feathers or a pound of tar? Use one word for the answer",
                "same"));
        manager.insert(20, new Decision( 10,
               "You see a fork in the road, where do you go?",
               "Left", "Right"));
        manager.insert(25, new Riddle(5, "The maker doesn't use it. The buyer doesn't want it. And the user doesn't see it. What is it?",
                "coffin"));
        manager.insert(30, new Decision(10,
                "It looks like the path splits ahead, where do you go?",
                "Right", "Left"));
        manager.insert(35, new Chance(5,
                "A dice is to be rolled, what number do you guess will be rolled? (1-6)",
                1, 6));
        manager.insert(40, new Chance(10,
                "Two dice are to be rolled, what number do you guess will be rolled? (2-12)",
                2, 12));
        manager.insert(45, new Riddle(5,
                "What gets bigger the more you take away from it?",
                "hole"));
        manager.insert(50, new Riddle(10, "What gets wet when drying?", "towel"));
        manager.insert(100, new End_Event(100, "This is the end event"));
        return manager;
    }

}
