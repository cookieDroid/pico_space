# Using Github Codespace as a c/c++ development environment for Raspberry Pico (w)

If you are stuck with a crappy laptop or cursed with windows OS with misconfigured c/c++ setup, use this repo as a template and create a workspace. All the files will be copied in to your new workspace. From there follow the setup instruction to install required tools.

## Creating codespace

There are two ways to create workspace.

1.using the template option available on top right corner of this repo. Click the dropdown and select open in a codespace.

![image](https://github.com/cookieDroid/pico_space/assets/69075360/fbda3433-ba4a-4630-9e2a-ee70c6db2724)

2.On the right side, click the code and then codespace option. You will be presented with an option to create a workspace using Github dev container. For details regarding usage, refer [here](https://docs.github.com/en/billing/managing-billing-for-github-codespaces/viewing-your-github-codespaces-usage).

![image](https://github.com/cookieDroid/pico_space/assets/69075360/cfbe8ac3-ccad-4109-8a47-d86859a4884b)

## setting up the tools in workspace
1. You will be greeted with a welcome page that let you customise vs code as per your wish.

![image](https://github.com/cookieDroid/pico_space/assets/69075360/0e72b9ba-8ce3-4807-88d0-ec6fcb9704e1)

2. Once you are satisfied with how it looks, select the terminal option and run the below commands to keep your system up to date.

       sudo apt update && sudo apt upgrade -y
  
&nbsp;&nbsp;&nbsp;&nbsp;The dev container is preinstalled with dot net, python, node js and conda. If you prefer your environment without unnecessary bloat you can uninstall them before updating the system.

3. At the end of the upgrade process you will be prompted to make a choice on version, click "install the package maintainer's version".

![image](https://github.com/cookieDroid/pico_space/assets/69075360/08c1d7be-f077-4f0e-962a-21b84bcdb493)

4. Once the system update is over, install the toolchain by running the below commands. The first command will download the script to download and install the required toolchains, SDK and placing them in default location.

       wget https://raw.githubusercontent.com/raspberrypi/pico-setup/master/pico_setup.sh

5. Provide executable permission for the script and run it.

       chmod +x pico_setup.sh
       ./pico_setup.sh

6. By the time the git submodules are being cloned, you will be prompted by code to install suggested extensions. Install the c/c++ extension pack and cmake tools extension.

7. The process ends with "E: Unable to locate package code", that's it all our tools are installed and ready to use now. Your explorer will look like this.
   
   ![image](https://github.com/cookieDroid/pico_space/assets/69075360/a8cd2bfe-0bb7-4628-9e0c-0367fe42a21a)

8. Enter the below command to add `PICO_SDK_PATH` to system environment variables to ensure absolute path is referred everywhere.
   
       export PICO_SDK_PATH=/workspaces/pico_space/pico/pico-sdk
   
## structure of the workspace

1. The workspace was created with a thought of having multiple projects with in a single repo. Examples for [single file project](https://github.com/cookieDroid/pico_space/tree/main/led_toggle) and [multiple file projects](https://github.com/cookieDroid/pico_space/tree/main/serial_test) are available as template.

2. Open any of the folder. Source and header files are always located in src folder.
  
3. Since this is not a single project per repo, there is no single build configuration, the build.sh inside each project will compile and build the output binary.

4. To create a new project, copy either of the two project available using the below command.

       cp -r led_toggle new_project

   ![image](https://github.com/cookieDroid/pico_space/assets/69075360/4959fe18-fbd9-4fad-bc02-cda420d0ec88)

5. In git, only the newly created files will appear. You can modify which files to include or neglect by modifying the gitignore file.

  ![image](https://github.com/cookieDroid/pico_space/assets/69075360/e2287bfe-db67-4a7f-9c0d-8981ff45e786)

7. Navigate to main.c file and try to include any header, autocomplete will work and start suggesting suitable header files.

   ![image](https://github.com/cookieDroid/pico_space/assets/69075360/be76593e-5998-468b-9b9c-490c232f3fa1)


## building and uploading binary file

1. Open the terminal and `cd` into src folder of your required project and run `./build.sh`.

2. To build binaries for pico wireless, edit the `build.sh` file and modify the below line and follow the instructions in the official [sdk guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

       cmake -DPICO_BOARD=pico_w ...

3. Now, if everthing is configured properly, output binaries will be available in {project_name}/src/src. Download main.uf2 and main.elf.

   ![image](https://github.com/cookieDroid/pico_space/assets/69075360/0373c454-cc6b-41ae-b05a-efe475cb8de2)

4. Press the bootsel button on pico and plug it in your system. It will open up file explorer. Drag and drop your uf2 file to pico's drive.

5. That's it, we have sucessfully created a workspace for pico and flashed it with our first example.

## Note

1. Considering remote webusb support is not yet enabled for codespace, it is not possible to debug the pico from web.

2. Make sure to stop the instace after usage to avoid billing time.

 

 
