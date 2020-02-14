TripleBit
(c) 2011 Massive Data Management Group @ SCTS & CGCL. 
	Web site: http://grid.hust.edu.cn/triplebit

This work is licensed under the Creative Commons
Attribution-Noncommercial-Share Alike 3.0 Unported License. To view a copy
of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/
or send a letter to Creative Commons, 171 Second Street, Suite 300,
San Francisco, California, 94105, USA.


Dependency:
-----------

~~Please install boost and raptor, you can use the following versions or other versions.~~

~~boost-1.39.0.tar.gz
raptor-1.4.21.tar.gz~~


On Ubuntu 18.04 / 18.10 / 19.04 / 19.10 run the commands below to install the perquisites for building TripleBit.
```bash
## install perquisites via apt
sudo apt install librdf0-dev libxml2-dev flex bison autopoint gtk-doc-tools libtool m4 automake gcc g++ build-essential git libboost-all-dev cmake
## compile old versions of libraries that are no longer in the ubuntu apt repos 
# old curl for raptor 
wget https://curl.haxx.se/download/archeology/curl-7.19.7.tar.gz
tar -xvzf curl-7.19.7.tar.gz
cd curl-7.19.7/
./configure
make -j
sudo make install
cd ../
# old raptor
wget http://download.librdf.org/source/raptor-1.4.21.tar.gz
tar -xvzf raptor-1.4.21.tar.gz
cd raptor-1.4.21
./autogen.sh 
./configure
make -j
sudo make install 
cd ../
```

Building:
---------

TripleBit must be build using GNU make and a reasonable C++ compiler. Ideally a simple

   make

is enough, it will build the tree high-level executables in bin/lrelease/.


Using:
------

TripleBit currently includes three high-level executables. The first `buildTripleBitFromN3`) is used to build a new database from an turtle/ntriples input:

    buildTripleBitFromN3 mydata.n3 database_directory

The input file can be arbitrarily large, the `buildTripleBitFromN3` spools to disk if main memory is exhausted.

The second (`buildTripleBitFromRDF`) is similar to the first executable except the input file is a rdf file.

After loading the database can be queried with `triplebitQuery`:

~~triplebitQuery database_directory query_directory~~
   
    triplebitQuery database_directory

The program shows a command prompt and accept SPARQL queries.
Just type your SPARQL query in a single line and press ENTER. 

Note: TripleBit currently only supports "select" queries.

