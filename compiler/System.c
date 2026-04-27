int Process[10];
int Success[10];

int MemPos;

int initUm;
int endUm;

int initDois;
int endDois;

int initTres;
int endTres;

int initQuatro;
int endQuatro;

int initCinco;
int endCinco;

int initSeis;
int endSeis;

int initSete;
int endSete;

int initOito;
int endOito;

int initNove;
int endNove;

int initDez;
int endDez;

void loadPID(int init, int end){
    int instPos;

    instPos = MemPos;
    while (init <= end){
        LOADInst(instPos, init);
        instPos = instPos + 1;
        init = init + 1;
    }
}

void execProc(int PID){
    int init;
    int end;

    init = 0;
    end = 0;

    if(PID == 1){
        init = initUm;
        end = endUm;
        LCDWrite(11);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(1);
        LCDWrite(21);
        execPID();
        LCDWrite(4);
        saveContext(1);
        changeContext(0);
    }
    if(PID == 2){
        init = initDois;
        end = endDois;
        LCDWrite(12);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(2);
        LCDWrite(22);
        execPID();
        LCDWrite(4);
        saveContext(2);
        changeContext(0);
    }
    if(PID == 3){
        init = initTres;
        end = endTres;
        LCDWrite(13);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(3);
        LCDWrite(23);
        execPID();
        LCDWrite(4);
        saveContext(3);
        changeContext(0);
    }
    if(PID == 4){
        init = initQuatro;
        end = endQuatro;
        LCDWrite(14);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(4);
        LCDWrite(24);
        execPID();
        LCDWrite(4);
        saveContext(4);
        changeContext(0);
    }
    if(PID == 5){
        init = initCinco;
        end = endCinco;
        LCDWrite(15);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(5);
        LCDWrite(25);
        execPID();
        LCDWrite(4);
        saveContext(5);
        changeContext(0);
    }
    if(PID == 6){
        init = initSeis;
        end = endSeis;
        LCDWrite(16);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(6);
        LCDWrite(26);
        execPID();
        LCDWrite(4);
        saveContext(6);
        changeContext(0);
    }
    if(PID == 7){
        init = initSete;
        end = endSete;
        LCDWrite(17);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(7);
        LCDWrite(27);
        execPID();
        LCDWrite(4);
        saveContext(7);
        changeContext(0);
    }
    if(PID == 8){
        init = initOito;
        end = endOito;
        LCDWrite(18);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(8);
        LCDWrite(28);
        execPID();
        LCDWrite(4);
        saveContext(8);
        changeContext(0);
    }
    if(PID == 9){
        init = initNove;
        end = endNove;
        LCDWrite(19);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(9);
        LCDWrite(29);
        execPID();
        LCDWrite(4);
        saveContext(9);
        changeContext(0);
    }
    if(PID == 10){
        init = initDez;
        end = endDez;
        LCDWrite(20);
        loadPID(init, end);
        LCDWrite(4);
        saveContext(0);
        changeContext(10);
        LCDWrite(30);
        execPID();
        LCDWrite(4);
        saveContext(10);
        changeContext(0);
    }
}

void main(void){
    int opcao;
    int PID;
    int qntProcessos;
    int i;
    int counter;
    int RR;
    int aux;

    MemPos = 3000;

    initUm = 0;
    endUm = 30;

    initDois = 200;
    endDois = 230;

    initTres = 400;
    endTres = 450;

    initQuatro = 600;
    endQuatro = 660;

    initCinco = 800;
    endCinco = 850;

    initSeis = 1000;
    endSeis = 1100;

    initSete = 1200;
    endSete = 1270;

    initOito = 1400;
    endOito = 1450;

    initNove = 1600;
    endNove = 1665;

    initDez = 1800;
    endDez = 1950;

    while(1 > 0){
        LCDWrite(1);
        opcao = input();
        counter = 0;
        RR = 0;
        aux = 0;

        if(opcao == 1){
            LCDWrite(3);
            PID = input();
            execProc(PID);          
        }
        if(opcao == 2){
            temporizador();
            LCDWrite(2);
            qntProcessos = input();
            i = 0;
            while(i < qntProcessos){
                LCDWrite(5);
                Process[i] = input();
                i = i + 1;
            }
            i = 0;
            while(i < qntProcessos){
                Success[i] = 0;
                i = i + 1;
            }
            while(counter < qntProcessos){
                PID = Process[RR];

                if(Success[RR] == 0){
                    execProc(PID);
                }
                RR = RR + 1;
                
                counter = 0;
                aux = 0;
                while(aux < qntProcessos){
                    counter = counter + Success[aux];
                    aux = aux + 1;
                }

                if (RR == qntProcessos){
                    RR = 0;
                }
            }
            temporizador();
        }
    }
}