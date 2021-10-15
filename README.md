# poco_examples
Studying possibilities of cross platform desktop applications with POCO.

## Development Requeriments

  #CMake
  ```
    Linux
    ```
      sudo snap install cmake --classic # Latest distribution version of cmake

    Windows
    ```
      Go to [cmake website](https://cmake.org/)
      On Download link. Get (Windows x64 ZIP).
      Extract the folder on desired cmake path.
      Add bin folder to PATH on Enviroment Variables.
    macOS
    ```      
      @TODO
  ```

### Windows Dependencies

  Microsoft Visual Studio Community 2019
  ```
    Install [Visual Studio 2019](https://visualstudio.microsoft.com/downloads/). Download the installer and select at least the following packages:
        - Desktop Development with C++
        - C++ CMake tools for Windows (Individual Components)
        - Git for Windows (Individual Components)
        - Ninja should already be included in this install by default

        On initial configuration using Visual Studio Compiler [MSVC 19.29.30133.0]

  Additional Packages Installation Manager [vcpkg] 
  ```
    - Download vcpkg package manager and do not follow the instructions yet.
    https://github.com/microsoft/vcpkg
    
    - Checkout vcpkg commit `d0268cf16649ffb8b847b719a9cab224623291ff` (master in 21/01/2021)
    - Follow the instructions on the vcpkg page to install (including integrations)
    
    - Create a system variable called VCPKG_ROOT pointing to the extracted folder;

    - Add the following paths to system variables path:
    "vcpkg folder path"
    "vcpkg folder path"\installed\x64-windows\bin
    "vcpkg folder path"\installed\x64-windows\debug\bin
    "vcpkg folder path"\installed\x64-windows\lib
    "vcpkg folder path"\installed\x64-windows\debug\lib

    -After installation of all Dependencies Packages restart the computer.

###POCO Library

  Installation
  ```
    Linux
    ```
      git clone https://github.com/pocoproject/poco.git
      sudo apt-get install openssl libssl-dev
      sudo apt-get install libmysqlclient-dev
      sudo apt-get install libpq-dev

      # On Windows platforms, ODBC should be readily available if you have the Windows SDK installed.
      sudo apt-get install libiodbc2 libiodbc2-dev

      cmake .
      sudo cmake --build . --target install
      @TODO install in usr/lib
      Moved all Poco libraries from /usr/local/lib to /usr/lib/, may also link in the OS.
    Windows
    ```  
      vcpkg.exe install POCO
    macOS
    ```      
      brew install poco
  ```
