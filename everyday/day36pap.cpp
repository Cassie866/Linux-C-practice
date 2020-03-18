#include<string>
#include<tuple>
#include<list>
#include<cstdio>//求n的阶乘
longlongfactorial(intn){longlongr=1;for(inti=1; i<=n; i++){r*=i;}returnr;}//求n,m 的组合C(n,m)//利用C(n,m)==C(n,n-m)的特点，计算容易的longlongcombination(intn,intm){intmax=m>(n-m)?m: (n-m);longlongnumerator=1;
for(inti=max+1; i<=n; i++){numerator*=i;}returnnumerator/factorial(n-max);}//重命名类型，类似于typedef作用usingPrePost=std::tuple<std::string,std::string>;//给出一棵树的前序+后序，利用最上面注释的原理//把每棵子树的前序+后序切分出来std::list<PrePost>splitSubTrees(std::stringconst&pre,std::stringconst&post){std::list<PrePost>list{};size_tpreIdx=1;size_tlastPost=0;while(preIdx<pre.size()){charrootValue=pre[preIdx];size_tpostIdx=post.find(rootValue);intcountOfNode=postIdx-lastPost+1;list.emplace_back(std::make_tuple(pre.substr(preIdx,countOfNode),post.substr(lastPost,countOfNode)));preIdx+=countOfNode;lastPost+=countOfNode;}returnlist;}//递归的求解每一层的可能性，直到树中只剩一个或者零个结点longlongcalculateNumOfPossibilities(intm,std::stringconst&pre,std::stringconst&post){if(pre.size()==0||pre.size()==1){return1;}std::list<PrePost>subTrees=splitSubTrees(pre,post);longlongresult=combination(m,subTrees.size());for(PrePostconst&prePost: subTrees){
result*=calculateNumOfPossibilities(m,
	std::get<0>(prePost),std::get<1>(prePost));}returnresult;}intmain(){intm;charpre[30];charpost[30];while(scanf("%d %s%s",&m,pre,post)!=EOF){printf("%lld\n",calculateNumOfPossibilities(m,pre,post));}return0;}
