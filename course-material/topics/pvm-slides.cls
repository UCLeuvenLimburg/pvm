\NeedsTeXFormat{LaTeX2e}
\ProvidesPackage{pvm}[2017/02/12]

\RequirePackage{tikz}
\RequirePackage{url}

\usetikzlibrary{calc,math}

\ProcessOptions\relax
\LoadClass{ucll-slides}

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

\endinput
