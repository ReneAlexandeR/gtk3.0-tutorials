#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
	gtk_init(&argc, &argv);											// Initialize GTK
	GtkWidget *window, *grid, *label, *button; 					// Initialize variables
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);					// Create main window
																	// Activate the "X" button to quit the main window
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

	// Insert program here
	
	/*
	*	This function creates a grid.
	*	Parameter 1: number of columns
	*	Parameter 2: number of rows
	*	Parameter 3: Homogeneity parameter (equal spacing for all widgets)
	*/
	grid = gtk_grid_new();
	button = gtk_button_new_with_mnemonic("_Button 1");
	label = gtk_label_new("Press button 1");
	gtk_grid_attach(GTK_GRID(grid),label,0,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),button,0,1,1,1);

	button = gtk_button_new_with_mnemonic("B_utton 2");
	label = gtk_label_new("Press button 2");
	gtk_grid_attach(GTK_GRID(grid),label,1,0,1,1);
	gtk_grid_attach(GTK_GRID(grid),button,1,1,1,1);

	gtk_container_add(GTK_CONTAINER(window),grid);					// Add the table to the main window

	// End program here
	gtk_widget_show_all(window);									// Show all widgets in main window
	gtk_main();														// Start the main loop

	return 0;
}
