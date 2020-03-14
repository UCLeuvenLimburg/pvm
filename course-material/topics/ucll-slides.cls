\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{ucll-slides}[2020/03/14]

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{beamer}}

\ProcessOptions\relax


\LoadClass{beamer}

\RequirePackage{graphicx}
\RequirePackage{pxfonts}
\RequirePackage{tikz}
\RequirePackage{calc}
\RequirePackage{listings}
\RequirePackage{booktabs}
\RequirePackage{pgfkeys}
\RequirePackage{url}
\RequirePackage{framed}
\RequirePackage{hyperref}
\RequirePackage{cleveref}
\RequirePackage{bbding}
\RequirePackage{wasysym}

\usetikzlibrary{shadows,calc,math,shapes,tikzmark}


\newcommand{\coursename}[1]{
  \newcommand{\ucll@slides@coursename}{#1}
}

\coursename{PVM}

\newcommand{\cpp}{C{\tt ++}}
\newcommand{\cake}{\ensuremath{(\pi)}}

\newcommand{\notrealcpp}{
  \begin{tikzpicture}[overlay,remember picture]
    \draw[fill=red,opacity=.5] (current page.north east) -- ++(0,-3) -- ++(-3,3) -- cycle;
    \node[rotate=-45,anchor=south,color=red] at ($ (current page.north east) + (-1.5,-1.5) $) {Not actual \cpp};
  \end{tikzpicture}
}

\newcommand{\drawboxaround}[1]{
  \draw[box] ($ (#1.south west) + (-.15,-.15) $) rectangle ($ (#1.north east) + (.15,.15) $);
}



\mode<presentation>
\usetheme[height=.75cm,compress]{Singapore}
% \setbeamertemplate{mini frames}{}
% \setbeamertemplate{background canvas}[vertical shading][top=blue!10,bottom=blue!30]

\institute[UCLL]{UC Leuven Limburg}
\author{Fr\'ed\'eric Vogels}
% \logo{\includegraphics[height=0.5cm]{../ucll-logo.png}}



% Tikz related commands
% \NODE{text}{id}
\newcommand{\NODE}[3][]{\tikz[baseline,remember picture]{\node[anchor=base,inner sep=0mm,#1] (#3) {{#2}};}}



\newcommand{\toc}{
  \begin{frame}
    \tableofcontents[sectionstyle=show/shaded,subsectionstyle=show/shaded/hide]
  \end{frame}
}


\setbeamertemplate{title page}{%
  \begin{center}
    {\sc\ucll@slides@coursename} \\
    {
      \newlength{\ucll@slides@coursenamewidth}
      \settowidth{\ucll@slides@coursenamewidth}{\sc\ucll@slides@coursename}
      \rule[10pt]{1.4\ucll@slides@coursenamewidth}{1pt} \\
    }
    {\sc\Huge \inserttitle}
  \end{center}
}

\newcommand{\link}[2]{\href{#1}{{\color{blue}#2}}}

\newenvironment{procontralist}{
  \begingroup
  \newcommand{\pro}{\item[\Checkmark]}
  \newcommand{\con}{\item[\XSolidBrush]}
  \begin{itemize}
  }{
  \end{itemize}
  \endgroup}

  \lstset{
    frame=lines,
    escapeinside=\`\`,
    basicstyle=\ttfamily,
    commentstyle=\color{green!50!black},
    showstringspaces=false,
    classoffset=0,
    keywordstyle=\color{blue}\bfseries,
    classoffset=1,
    keywordstyle=\color{darkgray}\bfseries,
    classoffset=0,
    numberstyle={\sffamily\tiny}
  }

  \lstdefinelanguage{python3}{
    keywords={False,class,finally,is,return,None,continue,for,lambda,try,True,def,from,nonlocal,while,and,del,global,not,with,as,elif,if,or,yield,assert,else,import,pass,break,except,in,raise},
    comment=[l]{\#},
    stringstyle=\color{purple},
    morestring=[b]",
    morestring=[b]',
  }

  \lstdefinelanguage{csharp}[Sharp]{C}{
    morekeywords={var,partial,abstract,as,base,byte,catch,checked,class,const,decimal,default,delegate,do,double,else,enum,event,explicit,extern,false,finally,fixed,float,foreach,implicit,in,interface,internal,is,lock,long,namespace,new,null,object,operator,out,override,params,private,protected,public,readonly,ref,sbyte,sealed,stackalloc,static,string,this,throw,true,try,typeof,uint,ulong,unchecked,unsafe,ushort,using,virtual,volatile,where,get,set},
    identifierstyle=\color{black},
    sensitive=false,
    comment=[l]{//},
    morecomment=[s]{/*}{*/},
    commentstyle=\color{purple}\ttfamily,
    stringstyle=\color{black}\ttfamily,
    morestring=[b]',
    morestring=[b]",
  }

  \lstdefinelanguage{c++14}{
    language=c++,
    morekeywords={override,constexpr,decltype,thread_local,noexcept,nullptr,static_assert,alignof,alignas,in}
  }

  \lstdefinelanguage{sdl}{
    morekeywords={push,pop,sphere,square,ambient,diffuse,specular,reflectivity,transparence,refractiveIndex,background,light,translate,scale,rotateX,rotateY,rotateZ},
    identifierstyle=\color{black},
    sensitive=true,
    comment=[l]{//},
    morecomment=[s]{/*}{*/},
  }

  \lstdefinelanguage{javascript}{
    keywords={abstract,arguments,await,boolean,break,byte,case,catch,char,class,const,continue,debugger,default,delete,do,double,else,enum,eval,export,extends,false,final,finally,float,for,function,goto,if,implements,import,in,instanceof,int,interface,let,long,native,new,null,package,private,protected,public,return,short,static,super,switch,synchronized,this,throw,throws,transient,true,try,typeof,var,void,volatile,while,with,yield},
    comment=[l]{\#},
    stringstyle=\color{purple},
    morestring=[b]",
    morestring=[b]',
  }


  % Code formatting
  \pgfkeys{
    /ucll/code/.cd,
    frame/.code=\lstset{frame=#1},
    font/.code=\lstset{basicstyle={\ttfamily #1}},
    width/.initial=.8\linewidth,
    language/.code=\lstset{language=#1},
    show line numbers/.code=\lstset{numbers=#1},
    show line numbers/.default=left,
    title/.code=\lstset{title=#1},
    @first line/.initial=1,
    first line/.style={@first line=#1},
    extra keywords/.code=\lstset{morekeywords=#1},
    @inline/.initial=0,
    inline/.style={@inline=1},
  }

  % \code[pgfkeys]{filename}
  \newcommand{\code}[2][]{
    {
      \pgfkeys{/ucll/code/.cd,#1,/ucll/code/@inline/.get=\code@inline}
      \ifnum\code@inline=0
        \begin{center}
          \pgfkeys{
            /ucll/code/width/.get=\code@width,
            /ucll/code/@first line/.get=\code@firstline,
          }
          \begin{minipage}{\code@width}
            \lstinputlisting[firstline=\code@firstline]{#2}
          \end{minipage}
        \end{center}
      \else
        {
          \pgfkeys{
            /ucll/code/width/.get=\code@width,
            /ucll/code/@first line/.get=\code@firstline,
          }
          \begin{minipage}{\code@width}
            \lstinputlisting[firstline=\code@firstline]{#2}
          \end{minipage}
        }
      \fi
    }
  }


  \pgfkeys{
    /ucll/code/underline/.cd,
    stroke/.style={red,thick},
    vertical offset/.initial=0.1,
    name center/.initial=center,
  }

  \newcommand{\codeunderline}[3][]{{
      \pgfkeys{
        /ucll/code/underline/.cd,
        #1,
        /ucll/code/underline/vertical offset/.get=\code@underline@verticaloffset,
        /ucll/code/underline/name center/.get=\code@underline@centername,
      }
      \tikz[remember picture,overlay]%
        \draw[/ucll/code/underline/stroke]%
          (pic cs:#2) --%
          ++(0,-\code@underline@verticaloffset) --%
          ($ (pic cs:#3) + (0,-\code@underline@verticaloffset) $) --%
          ++(0,\code@underline@verticaloffset);%
      \tikz[remember picture,overlay] \coordinate (\code@underline@centername) at ($ (pic cs:#2) ! 0.5 ! (pic cs:#3) + (0,-\code@underline@verticaloffset) $);
  }}

  \pgfkeys{
    /ucll/code/overline/.cd,
    stroke/.style={red,thick},
    vertical offset/.initial=0.1,
    vertical shift/.initial=0.2,
    name center/.initial=center,
  }

  \newcommand{\codeoverline}[3][]{{
      \pgfkeys{
        /ucll/code/overline/.cd,
        #1,
        /ucll/code/overline/vertical offset/.get=\code@overline@verticaloffset,
        /ucll/code/overline/vertical shift/.get=\code@overline@verticalshift,
        /ucll/code/overline/name center/.get=\code@overline@centername,
      }
      \tikz[remember picture,overlay]%
        \draw[/ucll/code/overline/stroke]%
          ($ (pic cs:#2) + (0,\code@overline@verticalshift) $) --%
          ++(0,\code@overline@verticaloffset) --%
          ($ (pic cs:#3) + (0,\code@overline@verticaloffset) + (0,\code@overline@verticalshift) $) --%
          ++(0,-\code@overline@verticaloffset);%
      \tikz[remember picture,overlay] \coordinate (\code@overline@centername) at ($ (pic cs:#2) ! 0.5 ! (pic cs:#3) + (0,\code@overline@verticaloffset) + (0,\code@overline@verticalshift) $);
  }}

  \newcommand{\codeunderlinex}[2][]{
    \codeunderline[name center=#2,#1]{#2 start}{#2 end}
  }

  \newcommand{\codeoverlinex}[2][]{
    \codeoverline[name center=#2,#1]{#2 start}{#2 end}
  }