#include  "ppexsi.hpp"

#include "pexsi/timer.h"

// #define _MYCOMPLEX_

#ifdef _MYCOMPLEX_
#define MYSCALAR Complex
#else
#define MYSCALAR Real
#endif
struct NodeInfo{
  int row;
  int col;
  double avg;
  double var;
  int avgRank;
  int varRank;
  NodeInfo(){
    avgRank = 0;
    varRank = 0;
  }
  NodeInfo(int row_, int col_, double avg_, double var_):row(row_), col(col_), avg(avg_), var(var_){
    avgRank = 0;
    varRank = 0;
  }
};

using namespace PEXSI;
using namespace std;

bool cmpAvg(struct NodeInfo x, struct NodeInfo y){
  return abs(x.avg) < abs(y.avg);
}
bool cmpVar(struct NodeInfo x, struct NodeInfo y){
  return x.var < y.var;
}
bool cmpRank(struct NodeInfo x, struct NodeInfo y){
  return (x.avgRank + x.varRank) < (y.avgRank + y.varRank);
}
int main(int argc, char *argv[])
{
    MPI_Init( &argc, &argv );


    int mpirank, mpisize;
    MPI_Comm_rank( MPI_COMM_WORLD, &mpirank );
    MPI_Comm_size( MPI_COMM_WORLD, &mpisize );    
    try{
        MPI_Comm world_comm;

        // *********************************************************************
        // Input parameter
        // *********************************************************************
        std::map<std::string,std::string> options;

        OptionsCreate(argc, argv, options);

        // Default processor number
        Int nprow = 1;
        Int npcol = mpisize;
        double delta = atof(options["-delta"].c_str());
        if( options.find("-r") != options.end() ){
            if( options.find("-c") != options.end() ){
                nprow= atoi(options["-r"].c_str());
                npcol= atoi(options["-c"].c_str());
                if(nprow*npcol > mpisize){
                    ErrorHandling("The number of used processors cannot be higher than the total number of available processors." );
                } 
            }
            else{
                ErrorHandling( "When using -r option, -c also needs to be provided." );
            }
        }
        else if( options.find("-c") != options.end() ){
            if( options.find("-r") != options.end() ){
                nprow= atoi(options["-r"].c_str());
                npcol= atoi(options["-c"].c_str());
                if(nprow*npcol > mpisize){
                ErrorHandling("The number of used processors cannot be higher than the total number of available processors." );
                } 
            }
            else{
                ErrorHandling( "When using -c option, -r also needs to be provided." );
            }
        }

        //?????????processor?????????????????????nprow * npcol????????????????????????world_comm????????????COMM
        MPI_Comm_split(MPI_COMM_WORLD, mpirank<nprow*npcol, mpirank, &world_comm);
    if (mpirank<nprow*npcol){
      //?????????????????????rank???size
      MPI_Comm_rank(world_comm, &mpirank );
      MPI_Comm_size(world_comm, &mpisize );
#if defined (PROFILE) || defined(PMPI) || defined(USE_TAU)
      TAU_PROFILE_SET_CONTEXT(world_comm);
#endif
      //????????????processor???????????????
      stringstream  ss;
      ss << "logTest" << mpirank;
      statusOFS.open( ss.str().c_str() );

      ///#if defined(COMM_PROFILE) || defined(COMM_PROFILE_BCAST)
      ///      stringstream  ss3;
      ///      ss3 << "comm_stat" << mpirank;
      ///      commOFS.open( ss3.str().c_str());
      ///#endif


      //if( mpisize != nprow * npcol || nprow != npcol ){
      //  ErrorHandling( "nprow == npcol is assumed in this test routine." );
      //}

      if( mpirank == 0 )
        cout << "nprow = " << nprow << ", npcol = " << npcol << endl;

      std::string Hfile, Sfile;
      int isCSC = true;
      if( options.find("-T") != options.end() ){
        //-T??????txt?????????CSC?????? 
        isCSC= ! atoi(options["-T"].c_str());
      }

      int checkAccuracy = false;
      if( options.find("-E") != options.end() ){ 
        //-E????????????
        //?????????????????????LU??????????????????
        checkAccuracy= atoi(options["-E"].c_str());
      }


      int doSelInv = 1;
      if( options.find("-Sinv") != options.end() ){ 
        //???????????????????????????1????????????
        doSelInv= atoi(options["-Sinv"].c_str());
      }


      int doFacto = 1;
      if( options.find("-F") != options.end() ){ 
        //??????
        doFacto= atoi(options["-F"].c_str());
      }

      int doSymbolic = 1;
      if( options.find("-Symb") != options.end() ){ 
        //??????
        doSymbolic= atoi(options["-Symb"].c_str());
      }

      int doConvert = 1;
      if( options.find("-C") != options.end() ){ 
        //??????
        doConvert= atoi(options["-C"].c_str());
      }

      int doDistribute = 1;
      if( options.find("-D") != options.end() ){ 
        //??????
        doDistribute= atoi(options["-D"].c_str());
      }

      Int doConstructPattern = 1;
      if( options.find("-Pattern") != options.end() ){ 
        doConstructPattern = atoi(options["-Pattern"].c_str());
      }

      Int doPreSelinv = 1;
      if( options.find("-PreSelinv") != options.end() ){ 
        //??????
        doPreSelinv = atoi(options["-PreSelinv"].c_str());
      }



      if(doSelInv){
        doConvert=1;
      }

      if(doConvert){
        doFacto=1;
      }

      if(doFacto){
        doDistribute=1;
      }

      if(doDistribute){
        doSymbolic = 1;
      }











      int doToDist = true;
      if( options.find("-ToDist") != options.end() ){ 
        //?
        doToDist= atoi(options["-ToDist"].c_str());
      }

      int doDiag = false;
      if( options.find("-Diag") != options.end() ){ 
        //?
        doDiag = atoi(options["-Diag"].c_str());
      }


      if( options.find("-H") != options.end() ){ 
        //??????H???????????????
        Hfile = options["-H"];
      }
      else{
        ErrorHandling("Hfile must be provided.");
      }

      if( options.find("-S") != options.end() ){ 
        //??????S???????????????
        Sfile = options["-S"];
      }
      else{
        statusOFS << "-S option is not given. " 
          << "Treat the overlap matrix as an identity matrix." 
          << std::endl << std::endl;
      }

      Int maxPipelineDepth = -1;
      if( options.find("-P") != options.end() ){ 
        //?
        maxPipelineDepth = atoi(options["-P"].c_str());
      }
      else{
        statusOFS << "-P option is not given. " 
          << "Do not limit SelInv pipelining depth." 
          << std::endl << std::endl;
      }

      Int symmetricStorage = 0;
      if( options.find("-SS") != options.end() ){ 
        //?
        symmetricStorage = atoi(options["-SS"].c_str());
      }
      else{
        statusOFS << "-SS option is not given. " 
          << "Do not use symmetric storage." 
          << std::endl << std::endl;
      }





      Int numProcSymbFact;
      if( options.find("-npsymbfact") != options.end() ){ 
        //?
        numProcSymbFact = atoi( options["-npsymbfact"].c_str() );
      }
      else{
        statusOFS << "-npsymbfact option is not given. " 
          << "Use default value (maximum number of procs)." 
          << std::endl << std::endl;
        numProcSymbFact = 0;
      }

      //rshift???shift???????????????z????????????????????????
      Real rshift = 0.0, ishift = 0.0;
      if( options.find("-rshift") != options.end() ){ 
        //?
        rshift = atof(options["-rshift"].c_str());
      }
      if( options.find("-ishift") != options.end() ){ 
        //?
        ishift = atof(options["-ishift"].c_str());
      }


      std::string ColPerm;
      if( options.find("-colperm") != options.end() ){ 
        //??????????????????????????????????????????????????????LU???sparsity pattern
        ColPerm = options["-colperm"];
      }
      else{
        statusOFS << "-colperm option is not given. " 
          << "Use MMD_AT_PLUS_A." 
          << std::endl << std::endl;
        ColPerm = "MMD_AT_PLUS_A";
      }

      // *********************************************************************
      // Read input matrix
      // *********************************************************************

      // Setup grid.
      SuperLUGrid<MYSCALAR> g( world_comm, nprow, npcol );

      int      m, n;
      DistSparseMatrix<MYSCALAR>  AMat;

      DistSparseMatrix<Real> HMat;
      DistSparseMatrix<Real> SMat;
      Real timeSta, timeEnd;
      GetTime( timeSta );
      if(isCSC)
        ParaReadDistSparseMatrix( Hfile.c_str(), HMat, world_comm );  
      else{
        ReadDistSparseMatrixFormatted( Hfile.c_str(), HMat, world_comm ); 
        ParaWriteDistSparseMatrix( "H.csc", HMat, world_comm ); 
      }

      if( Sfile.empty() ){
        // Set the size to be zero.  This will tell PPEXSI.Solve to treat
        // the overlap matrix as an identity matrix implicitly.
        SMat.size = 0;  
      }
      else{
        if(isCSC)
          ParaReadDistSparseMatrix( Sfile.c_str(), SMat, world_comm ); 
        else{
          ReadDistSparseMatrixFormatted( Sfile.c_str(), SMat, world_comm ); 
          ParaWriteDistSparseMatrix( "S.csc", SMat, world_comm ); 
        }
      }

      GetTime( timeEnd );
      LongInt nnzH = HMat.Nnz();
      if( mpirank == 0 ){
        cout << "Time for reading H and S is " << timeEnd - timeSta << endl;
        cout << "H.size = " << HMat.size << endl;
        cout << "H.nnz  = " << nnzH  << endl;
      }

      // Get the diagonal indices for H and save it n diagIdxLocal_
      //???????????????????????????????????????????????????????????????
      //??????????????????????????????zshift????????????????????????????????????
      std::vector<Int>  diagIdxLocal;
      { 
        Int numColLocal      = HMat.colptrLocal.m() - 1; //???????????????column?????????
        Int numColLocalFirst = HMat.size / mpisize;
        Int firstCol         = mpirank * numColLocalFirst;//?????????processor????????????????????????

        diagIdxLocal.clear();

        for( Int j = 0; j < numColLocal; j++ ){
          Int jcol = firstCol + j + 1;
          for( Int i = HMat.colptrLocal(j)-1; 
              i < HMat.colptrLocal(j+1)-1; i++ ){
            Int irow = HMat.rowindLocal(i);
            if( irow == jcol ){
              diagIdxLocal.push_back( i );//???????????????processor???????????????????????????????????????????????????????????????????????????
            }
          }
        } // for (j)
      }


      GetTime( timeSta );

      AMat.size          = HMat.size;
      AMat.nnz           = HMat.nnz;
      AMat.nnzLocal      = HMat.nnzLocal;
      AMat.colptrLocal   = HMat.colptrLocal;
      AMat.rowindLocal   = HMat.rowindLocal;
      AMat.nzvalLocal.Resize( HMat.nnzLocal );
      AMat.comm = world_comm;

      MYSCALAR *ptr0 = AMat.nzvalLocal.Data();
      Real *ptr1 = HMat.nzvalLocal.Data();
      Real *ptr2 = SMat.nzvalLocal.Data();

#ifdef _MYCOMPLEX_
      Complex zshift = Complex(rshift, ishift);
#else
      Real zshift = Real(rshift);
#endif

      if( SMat.size != 0 ){
        // S is not an identity matrix
        for( Int i = 0; i < HMat.nnzLocal; i++ ){
          AMat.nzvalLocal(i) = HMat.nzvalLocal(i) - zshift * SMat.nzvalLocal(i);
        }
      }
      else{
        // S is an identity matrix
        for( Int i = 0; i < HMat.nnzLocal; i++ ){
          AMat.nzvalLocal(i) = HMat.nzvalLocal(i);
        }

        for( Int i = 0; i < diagIdxLocal.size(); i++ ){
          AMat.nzvalLocal( diagIdxLocal[i] ) -= zshift;
        }
      } // if (SMat.size != 0 )

      LongInt nnzA = AMat.Nnz();
      if( mpirank == 0 ){
        cout << "nonzero in A (DistSparseMatrix format) = " << nnzA << endl;
      }


      GetTime( timeEnd );
      if( mpirank == 0 )
        cout << "Time for constructing the matrix A is " << timeEnd - timeSta << endl;

      //????????????????????????A?????????????????????
      // *********************************************************************
      // Symbolic factorization ?????????????????????A???LU????????????sparsity pattern????????????supernode???????????????
      // *********************************************************************
    

      GetTime( timeSta );
      SuperLUOptions luOpt;//????????????Super_LU?????????
      luOpt.ColPerm = ColPerm;
      luOpt.numProcSymbFact = numProcSymbFact;


      SuperLUMatrix<MYSCALAR> luMat(g, luOpt );//???????????????SuperLU Matrix??????????????????Super_LU???????????????


      luMat.DistSparseMatrixToSuperMatrixNRloc( AMat, luOpt );//???CSC???????????????SuperLU???CSR??????????????????????????????luMat???SuperMatrix???
      GetTime( timeEnd );
      if( mpirank == 0 )
        cout << "Time for converting to SuperLU format is " << timeEnd - timeSta << endl;

      if(doSymbolic){   
        GetTime( timeSta );
        luMat.SymbolicFactorize();//??????symbolic factorization
        luMat.DestroyAOnly();//????????????A?????????LU??????
        GetTime( timeEnd );

        if( mpirank == 0 )
          cout << "Time for performing the symbolic factorization is " << timeEnd - timeSta << endl;
      }

      // *********************************************************************
      // Numerical factorization only : LU??????
      // *********************************************************************

      Real timeTotalFactorizationSta, timeTotalFactorizationEnd; 


      // Important: the distribution in pzsymbfact is going to mess up the
      // A matrix.  Recompute the matrix A here.
      //??????pzsymbfact??????SuperMatrix???????????????????????????
      luMat.DistSparseMatrixToSuperMatrixNRloc( AMat ,luOpt);

      GetTime( timeTotalFactorizationSta );

      if(doDistribute){
        GetTime( timeSta );
        luMat.Distribute();//??????????????????????????????numerical factorization?????????????????????????????????
        GetTime( timeEnd );
        if( mpirank == 0 )
          cout << "Time for distribution is " << timeEnd - timeSta << " sec" << endl; 
      }


      if(doFacto){
        GetTime( timeSta );
        luMat.NumericalFactorize();//??????LU????????????????????????????????????Numerical Factorization??????????????????LUStruct??????
        GetTime( timeEnd );

        if( mpirank == 0 )
          cout << "Time for factorization is " << timeEnd - timeSta << " sec" << endl; 

        GetTime( timeTotalFactorizationEnd );
        if( mpirank == 0 )
          cout << "Time for total factorization is " << timeTotalFactorizationEnd - timeTotalFactorizationSta<< " sec" << endl; 


        // *********************************************************************
        // Test the accuracy of factorization by solve
        // *********************************************************************
        //?????????????????????????????????????????????
        if( checkAccuracy ) {
          SuperLUMatrix<MYSCALAR> A1( g, luOpt );
          SuperLUMatrix<MYSCALAR> GA( g, luOpt );
          A1.DistSparseMatrixToSuperMatrixNRloc( AMat,luOpt );
          A1.ConvertNRlocToNC( GA );

          int n = A1.n();
          int nrhs = 5;
          NumMat<MYSCALAR> xTrueGlobal(n, nrhs), bGlobal(n, nrhs);
          NumMat<MYSCALAR> xTrueLocal, bLocal;
          DblNumVec berr;
          UniformRandom( xTrueGlobal );

          GA.MultiplyGlobalMultiVector( xTrueGlobal, bGlobal );

          A1.DistributeGlobalMultiVector( xTrueGlobal, xTrueLocal );
          A1.DistributeGlobalMultiVector( bGlobal,     bLocal );

          luMat.SolveDistMultiVector( bLocal, berr );
          luMat.CheckErrorDistMultiVector( bLocal, xTrueLocal );
        }

        // *********************************************************************
        // Selected inversion
        // *********************************************************************

        if(doConvert || doSelInv>=1)
        {
          Real timeTotalSelInvSta, timeTotalSelInvEnd;

          NumVec<MYSCALAR> diag;
          PMatrix<MYSCALAR> * PMlocPtr;
          SuperNodeType * superPtr;
          GridType * g1Ptr;

          GetTime( timeTotalSelInvSta );

          g1Ptr = new GridType( world_comm, nprow, npcol );//????????????????????????????????????nprow * npcol?????????????????????supernode?????????
          GridType &g1 = *g1Ptr;

          superPtr = new SuperNodeType();
          SuperNodeType & super = *superPtr;

          GetTime( timeSta );
          luMat.SymbolicToSuperNode( super ); //??????sparsity pattern??????supernode

          PSelInvOptions selInvOpt;//??????PSelInv??????????????????
          selInvOpt.maxPipelineDepth = maxPipelineDepth;
          selInvOpt.symmetricStorage = symmetricStorage;

          FactorizationOptions factOpt;
          factOpt.ColPerm = ColPerm;//??????factorization??????????????????
          PMlocPtr = new PMatrix<MYSCALAR>( &g1, &super, &selInvOpt, &factOpt  );//PSelInv?????????????????????
          PMatrix<MYSCALAR> & PMloc = *PMlocPtr;

          if(doConvert){
            luMat.LUstructToPMatrix( PMloc );//???LU?????????????????????????????????????????????=???=
            GetTime( timeEnd );
          }

          LongInt nnzLU = PMloc.Nnz();
          if( mpirank == 0 ){
            cout << "nonzero in L+U  (PMatrix format) = " << nnzLU << endl;
          }

          //?????????processor??????????????????supernode???????????????????????????
          vector<struct NodeInfo> nodeInfos;
          int superNum = PMloc.NumSuper();
          const GridType* grid_ = PMloc.Grid();
          IntNumVec superPtr_ = super.superPtr;
          for(int ksup = 0;ksup<superNum;ksup++){
            if( MYCOL( grid_ ) == PCOL( ksup, grid_ ) ){//?????????processor???supernode????????????????????????processor?????????????????????supernode??????
              vector<LBlock<Real> >& Lcol = PMloc.L( LBj( ksup, grid_ ) );//???????????????LBlock
              for(LBlock<Real> LB : Lcol){//????????????L Block?????????????????????
                int col = ksup;//??????L Block??????
                int row = LB.blockIdx;//??????L Block??????
                NumMat<Real> nzval = LB.nzval;
                //????????????????????????
                double sum = 0;
                for(int j = 0;j<LB.numCol;j++){
                  for(int i = 0;i<LB.numRow;i++){
                    sum += nzval(i, j);
                  }
                }
                //???????????????
                int numCol = superPtr_(col + 1) - superPtr_(col);//??????supernode???????????????
                int numRow = superPtr_(row + 1) - superPtr_(row);//??????supernode???????????????
                double avg = sum / (numCol * numRow);
                //????????????
                double var = 0;
                for(int j = 0;j<LB.numCol;j++){
                  for(int i = 0;i<LB.numRow;i++){
                    var += (nzval(i, j) - avg) * (nzval(i, j) - avg);
                  }
                }
                var /= (numCol * numRow);
                //?????????L Block?????????????????????????????????
                struct NodeInfo tmp(row, col, avg, var);
                nodeInfos.push_back(tmp);
                // cout<<"("<<tmp.row<<","<<tmp.col<<"):"<<tmp.avg<<" "<<tmp.var<<endl;
              }
            }
          }
          //????????????MPI_Type?????????NodeInfo???????????????
          int blockLength[] = {1, 1, 1, 1, 1, 1};
          MPI::Datatype oldTypes[] = {MPI_INT, MPI_INT, MPI_DOUBLE, MPI_DOUBLE, MPI_INT, MPI_INT};
          MPI::Aint addressOffsets[6];
          struct NodeInfo tmp;
          MPI_Address(&tmp.row, &addressOffsets[0]);
          MPI_Address(&tmp.col, &addressOffsets[1]);
          MPI_Address(&tmp.avg, &addressOffsets[2]);
          MPI_Address(&tmp.var, &addressOffsets[3]);
          MPI_Address(&tmp.avgRank, &addressOffsets[4]);
          MPI_Address(&tmp.varRank, &addressOffsets[5]);
          addressOffsets[5] = addressOffsets[5] - addressOffsets[0];
          addressOffsets[4] = addressOffsets[4] - addressOffsets[0];
          addressOffsets[3] = addressOffsets[3] - addressOffsets[0];
          addressOffsets[2] = addressOffsets[2] - addressOffsets[0];
          addressOffsets[1] = addressOffsets[1] - addressOffsets[0];
          addressOffsets[0] = 0;
          MPI::Datatype newType = MPI::Datatype::Create_struct(6, blockLength, addressOffsets, oldTypes);
          newType.Commit();
          //????????????????????????????????????????????????MPI_Gatherv??????
          int *recvCount = NULL;
          if(mpirank == 0){
            recvCount = (int*)malloc(sizeof(int) * mpisize);
          }
          int cnt = nodeInfos.size();
          MPI_Gather(&cnt, 1, MPI_INT, recvCount, 1, MPI_INT, 0, world_comm);
          //????????????processor???????????????????????????
          struct NodeInfo* recvBuf = NULL;
          int* displs = NULL;
          int recvSize = 0;
          if(mpirank == 0){
            displs = (int*)malloc(sizeof(int) * mpisize);
            displs[0] = 0;
            for(int i = 1;i<mpisize;i++){
              displs[i] = displs[i - 1] + recvCount[i - 1];
            }
            recvSize = displs[mpisize - 1] + recvCount[mpisize - 1];
            recvBuf = (struct NodeInfo*)malloc(sizeof(struct NodeInfo) * recvSize);
          }
          MPI_Gatherv(nodeInfos.data(), nodeInfos.size(), newType, recvBuf, recvCount, displs, newType, 0, world_comm);
          if(mpirank == 0){
            // for(int i = 0;i<recvSize;i++){
            //   cout<<"(" <<recvBuf[i].row << "," <<recvBuf[i].col <<"):"<<recvBuf[i].avg<<" "<<recvBuf[i].var<<endl;
            // }
            // //??????????????????????????????????????????????????????????????????????????????
            // sort(recvBuf, recvBuf + recvSize, cmpAvg);
            // for(int i = 0;i<recvSize;i++){
            //   recvBuf[i].avgRank = i;
            // }
            // //?????????????????????????????????????????????
            // sort(recvBuf, recvBuf + recvSize, cmpVar);
            // for(int i = 0;i<recvSize;i++){
            //   recvBuf[i].varRank = i; 
            // }
            // //????????????????????????
            // sort(recvBuf, recvBuf + recvSize, cmpRank);
            // ofstream superCol;
            // superCol.open("my_superInfo");
            // for(int i = 0;i<recvSize;i++){
            //   string pos = "(" + to_string(recvBuf[i].row) + "," + to_string(recvBuf[i].col) + ")";
            //   superCol << pos << "\t\t\t\t" << recvBuf[i].avg << "\t\t\t\t" << recvBuf[i].var << endl;
            // }
            // superCol.close();
            //???????????????????????????
            sort(recvBuf, recvBuf + recvSize, cmpAvg);
            string chose = "";
            for(int i = 0;i<recvSize;i++){
              if(recvBuf[i].avg > delta){
                break;
              }
              chose += " " + to_string(recvBuf[i].row) + "," + to_string(recvBuf[i].col);
            }
            cout<<chose<<endl;
          }
          //????????????????????????
          newType.Free();
          free(recvBuf);
          free(recvCount);
          free(displs);
          
          delete PMlocPtr;
          delete superPtr;
          delete g1Ptr;

        }
      }
        statusOFS.close();
    
  }
    }catch( std::exception& e ){
        std::cerr << "Processor " << mpirank << " caught exception with message: "
        << e.what() << std::endl;
    }

    MPI_Finalize();

    return 0;
}
