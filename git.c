sudo apt-get install git
git config --global user.name "haitao"
git config --global user.email  acer_yuhaitao@163.com

ssh-keygen  ##һֱĬ�ϾͿ����� 
ssh-rsa 
linux@ubuntu:~/Git/project$ git config --global user.name "haitao"
linux@ubuntu:~/Git/project$ git config --global user.email  acer_yuhaitao@163.com
linux@ubuntu:~/Git/project$ cat ~/.gitconfig
[user]
	name = haitao
	email = acer_yuhaitao@163.com
[color]
	ui = always
linux@ubuntu:~/Git/project$  git commit -m '1st commit'
[master (root-commit) 453855d] 1st commit
 1 file changed, 9 insertions(+)
 create mode 100644 main.c
linux@ubuntu:~/Git/project$ rm -rf main.c 
linux@ubuntu:~/Git/project$ ls
linux@ubuntu:~/Git/project$ git checkout -f HEAD
linux@ubuntu:~/Git/project$ ls
main.c

git init
��linux�´git����
1������Github�˺ţ�https://github.com
2��Linux����SSH��Կ��
[plain] view plain copy
ssh-keygen  ##һֱĬ�ϾͿ�����  
3������Կ���뵽Github�˻���ϢAccount Settings->SSH Key
4��������֤�Ƿ�ɹ���
[plain] view plain copy
ssh -T git@github.com  
Hi someone! You've successfully authenticated, but GitHub does not provide shell access.  

ͬ��github������
1��������Ŀ�����أ�
[plain] view plain copy
git clone git://github.com:xxxx/test.git ##��gitreadonly��ʽ��¡�����أ�ֻ���Զ�  
git clone git@github.com:xxx/test.git  ##��SSH��ʽ��¡�����أ����Զ�д  
git clone https://github.com/xxx/test.git ##��https��ʽ��¡�����أ����Զ�д  
git fetch git@github.com:xxx/xxx.git  ##��ȡ�����ص����ϲ�  
git pull git@github.com:xxx/xxx.git ##��ȡ���ϲ����ݵ�����  

�����ύ��Ŀ��github
1����������
[plain] view plain copy
git config --global user.name 'onovps'  
git config --global user.email 'onovps@onovps.com' #ȫ����ϵ��ʽ����ѡ  
2���½�Git��Ŀ���ύ��Github��
[plain] view plain copy
mkdir testdir & cd testdir  
touch README.md  
git init #��ʼ��һ�����ؿ�  
git add README.md #����ļ������زֿ�  
git rm README.md #���ص�����ɾ��  
git commit -m "first commit" #�ύ�����ؿⲢ��ע����ʱ������ڱ��ء�  
git commit -a  ##�Զ����±仯���ļ���a�������Ϊauto  
git remote add xxx git@github.com:xxx/xxx.git  #����һ��Զ�̷������ı����� 
 git remote add haitao git@github.com:acer-haitao/Haitao.git
git remote rm xxx   ##ɾ��Զ�̰汾��ı���  
git remote -v

git push -u haitao master #�������ļ��ύ��Github��remoname�汾���С���ʱ�Ÿ����˱��ر����github�����ϡ�  

��֧�汾����
1�������ͺϲ���֧
[plain] view plain copy
git branch #��ʾ��ǰ��֧��master  
git branch new-feature  #������֧  
git checkout new-feature  #�л����·�֧  
vi page_cache.inc.php  
git add page_cache.inc.php  
git commit -a -m "added initial version of page cache"  
git push origin new-feature  ##�ѷ�֧�ύ��Զ�̷�������ֻ�ǰѷ�֧�ṹ�������ύ��Զ�̣���û�з��������ɵĺϲ���Ϊ��  
2�����new-feature��֧�����ˣ������б�Ҫ�ϲ���master
[plain] view plain copy
git checkout master  #�л���������  
git merge new-feature  ##�ѷ�֧�ϲ�������  
git branch #��ʾ��ǰ��֧��master  
git push  #��ʱ������Ҳ�ϲ���new-feature�Ĵ���  

vim /etc/hosts

192.30.253.112 github.com
ssh-add .ssh/my_heroku_key_rsa

