
    for(int i=0; i<numProduction; i++ ){
        cin>>production[i];
    }
    while (true)
    {
        cout<<"Find the expression";
        cin>>inputSymbol;
        result[0]='\0';
        for(int i=0; result[i]!='\0';i++){
            cout<<result[i]<<" "
        }
        cout<<endl;
        cout<<"do you want to continue";
        cin>>choice;
        if(choice!='y' || choice!='Y'){
            break;
        }