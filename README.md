# poco_examples
Studying possibilities of cross platform desktop applications with POCO.

  #POCO Library
    ```
    git clone https://github.com/pocoproject/poco.git
    sudo apt-get install openssl libssl-dev
    sudo apt-get install libmysqlclient-dev
    sudo apt-get install libpq-dev
    ```
    ```
    # On Windows platforms, ODBC should be readily available if you have the Windows SDK installed.
    sudo apt-get install libiodbc2 libiodbc2-dev
    ```
    sudo cmake --build . --target install
    Instalation links to /usr/local/lib

    ``` Got some linker errors
    @TODO install in usr/lib
    To solve it quickly I copied all Poco libraries from /usr/local/lib to /usr/lib/, it worked for me.
