
using Gtk;
using GLib;
extern bool turn_off();

public class Gui : Window {

	public ProgressBar bar;
	public Box box_root;
	public Box box_buttons;
	public Button btn_pause;
	public Button btn_skip;
	public Button btn_set;
	public Button btn_config;
	public Button btn_about;
	public bool bool_again = false;
	public bool bool_paused = false;
	public int current_time = 3;

	public Gui() {

		try {
            this.icon = new Gdk.Pixbuf.from_file("../res/min_screen_sleeper_icon_1.5.ico");
        } catch(Error e) {
            stderr.printf("Could not load application icon: %s\n", e.message);
        }

		// Prepare Window:
		this.title = "Minimalist Screen Sleeper v1.5";
		this.window_position = WindowPosition.CENTER;
		this.destroy.connect(main_quit);
		this.resizable = false;
		//this.set_default_size(500, 30);
		this.set_keep_above(true);

		//this.set_opacity(0.5);
		//this.decorated = false;
		//this.resize_to_geometry(300, 30);

		box_root = new Box(Orientation.VERTICAL, 5);
		box_root.homogeneous = true;

		// The ProgressBar:
		bar = new ProgressBar();
		bar.inverted = true;
		box_root.add(bar);

		box_buttons = new Box(Orientation.HORIZONTAL, 1);
		box_buttons.homogeneous = true;

		btn_pause = new Button.with_mnemonic("Pause");
		btn_skip = new Button.with_mnemonic("Skip");
		btn_set = new Button.with_mnemonic("Set Custom");
		btn_config = new Button.with_mnemonic("Change settings");
		btn_about = new Button.with_mnemonic("About");

		btn_pause.clicked.connect( () => {

			if( bool_paused == false ) {
				bool_paused = true;

			} else {
				bool_paused = false;
				btn_pause.set_label("Pause");
				progress();
			}
		});

		btn_skip.clicked.connect( () => {
			current_time = 0;
			if( bool_paused == true ) {
				bool_paused = false;
				progress();
			}
		});

		btn_set.clicked.connect( () => {

			if( bool_paused == false )
				bool_paused = true;

			InputDialog dialog = new InputDialog(this);
			dialog.show_all();

		});

		btn_config.clicked.connect( () => {

			if( bool_paused == false )
				bool_paused = true;

			SettingDialog dialog = new SettingDialog(this);
			dialog.show_all();

		});

		btn_about.clicked.connect( () => {

			if( bool_paused == true )
				bool_paused = false;
			else
				bool_paused = true;

			btn_pause.set_label("Paused");

			var dialog = new Gtk.MessageDialog(
				null,
				Gtk.DialogFlags.MODAL,
				Gtk.MessageType.INFO,
				Gtk.ButtonsType.OK,
				"Minimalist Screen Sleeper v1.5\nBy Raymel Francisco"
			);

			dialog.set_title("About Minimalist Screen Sleeper");
			dialog.run();
			dialog.destroy();

			if( bool_paused == true )
				bool_paused = false;
			else
				bool_paused = true;

			btn_pause.set_label("Pause");
			progress();

		});

		box_buttons.add(btn_pause);
		box_buttons.add(btn_skip);
		box_buttons.add(btn_set);
		box_buttons.add(btn_config);
		box_buttons.add(btn_about);

		box_root.add(box_buttons);

		this.add(box_root);

		bar.set_text("Turning off monitor...");
		bar.set_fraction(1);

		// open file
		read_config();

		// first try
		this.progress();

	}

	public void read_config() {
		try {
			//
			// Read data:
			//

			KeyFile file = new KeyFile();

			// Use ',' as array-element-separator instead of ';'.
			file.set_list_separator(',');

			// file.load_from_file ("my-keyfile.conf", KeyFileFlags.NONE);
			file.load_from_file("settings.ini", KeyFileFlags.NONE);


			// ** OptionalGroup
			// Check availability before accessing to avoid exceptions:
			if( file.has_group("WaitDuration") ) {
				current_time = file.get_integer("WaitDuration", "seconds");
			}

			//
			// Modify data:
			//

			/*
			file.set_string ("BasicValues", "String", "my-new-value");
			file.remove_group ("LocalizedString");
			file.remove_group ("OptionalGroup");
			file.remove_key ("Lists", "StringArray");
			*/

		} catch (KeyFileError e) {
			stdout.printf("Error: %s\n", e.message);
		} catch (FileError e) {
			// create file

		}
	}

	public void progress() {

		bar.set_show_text(true);

		double step = 1 / ( (double) current_time + 1);
		double progress = bar.get_fraction();

		// Fill the bar:
		GLib.Timeout.add(1000, () => {

			// if paused
			if( bool_paused == true ) {
				btn_pause.set_label("Resume");
				return false;
			}

			// Get the current progress:

			bar.set_text( "Turning off monitor in %ds".printf(current_time) );
			
			// Update the bar:
			progress -= step;
			bar.set_fraction(progress);

			if( current_time == 0 ) {

				bar.set_text("Turning off monitor...");
				bar.set_fraction(0);
				turn_off();
				Gtk.main_quit();

				//bool a = false;
				//int c = 10000;
				/*
				GLib.Timeout.add( c, () => {
					/*
					if ( a = show_message("Turn off?", this, Gtk.MessageType.QUESTION) ) {

						stdout.puts("OK");
						this.progress();

					} else {
						Gtk.main_quit();
					}*/
					/*
					if( bool_again == true ) {
						this.progress();
						bool_again = false;
						return true;
					}
					else
						Gtk.main_quit();
				});*/
					
			}

			current_time--;

			// Repeat until 100%
			return current_time > -1;
		});
		
	}
/*
	private bool show_message(string message, Gtk.Window window, Gtk.MessageType mt) {
		
		Gtk.MessageDialog m = new Gtk.MessageDialog(window, DialogFlags.MODAL, mt, ButtonsType.OK_CANCEL, message);
	    Gtk.ResponseType result = (ResponseType) m.run();
	    m.close();
	    
	    return result == Gtk.ResponseType.OK;
	}
*/
	public static int main (string[] args) {
		
		init(ref args);

		Gui win = new Gui();
		win.show_all();
		Gtk.main();

		return 0;
	}

	class InputDialog : Dialog {

		public InputDialog(Gui parent) {
			this.title = "Enter seconds";
			this.window_position = WindowPosition.CENTER;
			this.set_default_size(150, 50);
			this.set_keep_above(true);
			Box box_root = new Box(Orientation.VERTICAL, 5);

			SpinButton spn_sec = new SpinButton.with_range(0, 32000, 1);
			box_root.add(spn_sec);

			Button btn_ok = new Button.with_mnemonic("OK");
			box_root.add(btn_ok);

			get_content_area().add(box_root);

			btn_ok.clicked.connect( () => {
				parent.current_time = spn_sec.get_value_as_int();
				parent.bar.set_fraction(1);
				
				if( parent.bool_paused == true )
					parent.bool_paused = false;
				
				this.close();
				parent.btn_pause.set_label("Pause");
				parent.progress();
			});

		}

	}


	class SettingDialog : Dialog {

		public SettingDialog(Gui parent) {
			this.title = "Edit settings";
			this.window_position = WindowPosition.CENTER;
			this.set_default_size(150, 50);
			this.set_keep_above(true);
			Box box_root = new Box(Orientation.VERTICAL, 5);

			Box box_1 = new Box(Orientation.HORIZONTAL, 5);
			box_1.add(new Gtk.Label("	Wait Duration:	"));
			SpinButton spn_sec = new SpinButton.with_range(0, 32000, 1);
			spn_sec.set_value(5);
			box_1.add(spn_sec);
			box_root.add(box_1);

			Box box_2 = new Box(Orientation.HORIZONTAL, 5);
			box_2.add(new Gtk.Label("	Pause Hotkey (ASCII):	"));
			Entry pause_key = new Entry();
			pause_key.set_text("32");
			box_2.add(pause_key);
			box_root.add(box_2);

			Box box_3 = new Box(Orientation.HORIZONTAL, 5);
			box_3.add(new Gtk.Label("	Skip Hotkey (ASCII):	"));
			Entry skip_key = new Entry();
			skip_key.set_text("115");
			box_3.add(skip_key);
			box_root.add(box_3);

			Box box_4 = new Box(Orientation.HORIZONTAL, 5);
			CheckButton show_console = new Gtk.CheckButton.with_label("Console MODE");
			box_4.add(show_console);
			box_root.add(box_4);

			Button btn_save = new Button.with_mnemonic("Save");
			box_root.add(btn_save);

			get_content_area().add(box_root);

			btn_save.clicked.connect( () => {

				try {

					KeyFile file = new KeyFile();

					// Use ',' as array-element-separator instead of ';'.
					file.set_list_separator(',');
					file.load_from_file("settings.ini", KeyFileFlags.NONE);

					if( file.has_group("WaitDuration") ) {
						//current_time = file.get_integer("WaitDuration", "seconds");
						file.set_string("WaitDuration", "seconds", spn_sec.get_value_as_int().to_string());
					}

					if( file.has_group("AtRuntime") ) {
						//current_time = file.get_integer("WaitDuration", "seconds");
						file.set_string("AtRuntime", "pause", pause_key.get_text());
						file.set_string("AtRuntime", "skip", skip_key.get_text());
					}

					if( file.has_group("ShowConsoleWindow") ) {
						if(show_console.active) {
							file.set_string("ShowConsoleWindow", "show", "yes");
						} else {
							file.set_string("ShowConsoleWindow", "show", "no");
						}
					}

					//file.save_to_file("settings.ini");
					string updated_data = "# This file is auto-generated by Minimalist Screen Sleeper.";
					updated_data += "\n# EDITING THIS FILE IS NOT ADVISABLE.";
					updated_data += "\n# Sincerely,\n# The Developer";
					updated_data += file.to_data();

					//var dos = new DataOutputStream(File.new_for_path ("settings.ini").create(FileCreateFlags.REPLACE_DESTINATION));
			        //dos.put_string(updated_data);

			        stdout.puts(updated_data);

			        try {
			            FileUtils.set_contents("settings.ini", updated_data, updated_data.length);
			        } catch (FileError err) {
			            warning(err.message);
			        }

					//
					// Modify data:
					//

					/*
					file.set_string ("BasicValues", "String", "my-new-value");
					file.remove_group ("LocalizedString");
					file.remove_group ("OptionalGroup");
					file.remove_key ("Lists", "StringArray");
					*/

				} catch (KeyFileError e) {
					stdout.printf("Error: %s\n", e.message);
				} catch (FileError e) {
					// create file
				}

				parent.current_time = spn_sec.get_value_as_int();
				parent.bar.set_fraction(1);
				
				if( parent.bool_paused == true )
					parent.bool_paused = false;
				
				this.close();
				parent.btn_pause.set_label("Pause");
				parent.progress();
			});

		}

	}
}
