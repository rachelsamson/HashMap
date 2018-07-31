template<typename T1,typename T2>
	T2 hashmap<T1,T2>::m_search(T1 Key)
	{
		const uint32_t stringVal[]={Key};
		int lenght=( sizeof(stringVal)/sizeof(uint32_t));
		uint32_t ABC=JenkinsHash(stringVal,lenght, 33);
		int index=(ABC/100000000)/2;
		struct hashnode<T1,T2> *temp=&nodeptr[index];
		temp->left=nodeptr[index].left;
		temp->right=nodeptr[index].right;
		while((temp!=NULL) && (temp->key!=Key))
		{
			if(Key < temp->key)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(temp==NULL)
			return false;
		else
			return temp->value;

	} 
