# CLion setup and common operations

### Pre-requisite software

* CLion (there's an option for non-commercial account and software). During installation, leave things to defaults.
* Python 3
* Git
* (**Mac users only**) [Homebrew](https://brew.sh/)

### First-time installation

* (**Mac users only**) From a terminal, run ```brew install pkg-config```
  * Do not forget to add path as instructed when installing brew - pay attention to "**==> Next steps:** Run these commands..."
* Clone or download/unzip repository. Do **NOT** place it in a network folder, Dropbox, OneDrive, Google Drive, etc. Also do **NOT** place it in a path that contains spaces.
* In CLion, click "Open" and select the repository folder. Make sure you "Trust the project folders"
* In the project wizard click 'Skip Wizard and Use Defaults' - you don't need to change anything here
* When the project opens, you might notice red fonts indicate an error when loading the project, regarding not finding a package configuration file provided by SFML. **This is normal**. We need to proceed to the next steps to make the error go away
* There's a burger menu on the top left, which expands to a typical application menu, with top-level entries like "File", "View", etc
  * (**Mac users only**) You might not see a burger menu, as in typical Mac fashion the application menu could already be at the top of the screen 
* Go to View -> Tool Windows -> Vcpkg
* At the bottom left in the new Vcpkg window, click "+", ensure both checkboxes are selected, ensure that the vcpkg path does **NOT** contain spaces, and click OK.
* In the "Project" view, right-click the folder root, and select "Reload CMake Project"
* By now everything should be ok, and the different build targets should appear on the top middle-right of the screen, on the right of the active configuration, which should be "Debug"

### Creating a new project

* In a command prompt or PowerShell, navigate to the project folder, or in CLion, click on the terminal icon (bottom-left) <img width="39" height="37" alt="image" src="https://github.com/user-attachments/assets/3e7b3db3-82fb-4570-a04c-a30de10e01b5" />
* Call "python create_project.py YourProjectName" to create a new project. If you don't provide a name, it defaults to MyNewSFMLApp. If the project folder exists, the script refuses to continue, to avoid overwriting existing projects. Please use CamelCase for names, and don't use any special characters or spaces
* Now back in CLion, in the "Project" view, right-click the folder root, and select "Reload CMake Project"

### Adding a .cpp or .h file

* Find the corresponding project in the Project view, and right-click on the "src" subfolder
* Select New -> C/C++ Source File
* Type a name, select "Create an associated header" if you need it, and select OK

### Deleting a .cpp or .h file

* Right-click on the file you wish to delete
* Select Delete... and press OK
