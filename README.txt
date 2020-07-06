{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf100
{\fonttbl\f0\fnil\fcharset0 HelveticaNeue;\f1\fswiss\fcharset0 Helvetica;\f2\fnil\fcharset0 Menlo-Regular;
}
{\colortbl;\red255\green255\blue255;\red27\green31\blue34;\red255\green255\blue255;\red0\green0\blue0;
}
{\*\expandedcolortbl;;\cssrgb\c14118\c16078\c18039;\cssrgb\c100000\c100000\c100000;\csgray\c0;
}
\margl1440\margr1440\vieww10800\viewh8980\viewkind0
\deftab720
\pard\pardeftab720\sl360\sa200\partightenfactor0

\f0\fs32 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 The purpose of this basic C integrator is to find the numerical position-momentum solution of a Newtonian particle given arbitrary initial conditions. It implements 4 basic techniques (forwards Euler, backwards Euler, trapezoid, and leapfrog).
\f1\fs24 \cf0 \cb1 \kerning1\expnd0\expndtw0 \outl0\strokewidth0 \
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0
\cf0 \
To compile the program, run the following command in Mac Terminal:\
\
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f2\fs22 \cf4 \cb3 \CocoaLigature0 	gcc main.c vector_mtx.c forces.c analysis.c init.c evolve.c -o exec -lm\
\
\
This will make a Unix executable named \'91exec\'92. Execute the source code using provided initial data with the command:\
\
	./exec InputParams.txt }