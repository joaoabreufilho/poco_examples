# poco_examples
Studying possibilities of cross platform desktop applications with POCO.

## Requeriments

- Using the terminal, the following packages must be installed:
```
  - Clone and install dependencies.
      
      ```
        git clone https://github.com/pocoproject/poco.git
        
      ```
        sudo apt-get install openssl libssl-dev
        
      ```
        sudo apt-get install libmysqlclient-dev
        
      ```
        sudo apt-get install libpq-dev
        
      ```
        # On Windows platforms, ODBC should be readily available if you have the Windows SDK installed.

        sudo apt-get install libiodbc2 libiodbc2-dev
        ```
    - Install Library.
            
      ```
        sudo cmake --build . --target install

    - Problem:
                
      ```
        Instalation links to /usr/local/lib - Got some linker errors with cmake

      ```
        @todo install in usr/lib
                    
      ```
        To solve it quickly I copied all Poco libraries from /usr/local/lib to /usr/lib/, it worked for me.
