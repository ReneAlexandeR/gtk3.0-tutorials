#include <gtk/gtk.h>

static void button_clicked(GtkWidget button, gpointer data)
{
	g_print("GAS is released!\n");
}

int main (int argc, char* argv[])
{
	/* First thing to do in a GTK application*/
	gtk_init(&argc, &argv);
	
	// Create a GTK item or widget (the GtkWidget type is used in almost any type of element)
	GtkWidget *window, *label, *button;
	/* 
	* Then you use the gtk_xxxx_new to create the element and make the widget point to it.
	* It is worth noticing the syntax of GTK's API:
	* gtk_element_action 
	*/
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button = gtk_button_new_with_label("Fart!");
	// label = gtk_label_new("Hello jackass");


	/*
	* This function will connect a signal or an event from the screen with a function.
	* Parameter 1: what widget will it listen to. 
	* Parameter 2: what event will it respond to.
	* Parameter 3: which function will respond to the event, the macro G_CALLBACK must be used.
	* Parameter 4: parameter to pass to the callback function.
	*/
	g_signal_connect(window, "delete-event",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked),NULL);
	/*
	* This function will add an element inside a container. A container can be any type of widget.
	* In order to use this function, we have to cast the elements to gtk containers using the 
	* shown macro.
	* Parameter 1: the receiving element cast into a container.
	*/
	// gtk_container_add(GTK_CONTAINER(window), label);
	gtk_container_add(GTK_CONTAINER(window), button);

	// This function gives visibility to the created elements in this program.
	// Always include before gtk_main()
	// gtk_widget_show(window); -------------------> only one widget
	// gtk_widget_show_all();   -------------------> show all widgets, pass the root element
	gtk_widget_show_all(window);

	/* Last thing to do in a GTK application */
	gtk_main();
	return 0;

}
