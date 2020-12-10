\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{homework}[2020/11/24]

\newcommand{\professor}[1]{\newcommand{\professorloc}{#1}}
\newcommand{\class}[1]{\newcommand{\classlocal}{#1}}
\newcommand{\institute}[1]{\newcommand{\instituteloc}{#1}}

\newcommand{\CourseLang}{Course}
\newcommand{\StudentLang}{Student name}
\newcommand{\ProfessorLang}{Professor}

\RequirePackage{fancyhdr}

\DeclareOption{twocolumn}{\OptionNotUsed}
\DeclareOption{twoside}{\OptionNotUsed}

\DeclareOption{german}{
    \renewcommand{\CourseLang}{Kurs}
    \renewcommand{\StudentLang}{Studenten}
    \renewcommand{\ProfessorLang}{Professor}
}

\PassOptionsToClass{a4paper}{scrartcl}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{scrartcl}}

\ProcessOptions\relax

\LoadClass{scrartcl}

\RequirePackage{amsmath}
\RequirePackage{mathtools}
\RequirePackage{amssymb}
\RequirePackage{icomma}

\RequirePackage{enumitem}
\setenumerate{label=\alph*)}

\RequirePackage{titlesec}
\titleformat{\section}[block]{\normalsize\bfseries\filcenter}{\thesection.}{.3cm}{}
\titleformat{\subsection}[runin]{\bfseries}{\thesubsection.}{1mm}{}[.\quad]
\titleformat{\subsubsection}[runin]{\bfseries\itshape}{\thesubsubsection.}{1mm}{}[.\quad]

\RequirePackage{geometry}
\geometry{left=2.5cm,right=2.5cm,top=2.5cm,bottom=2.5cm}

\fancyhead{}
\fancyfoot{}
\pagestyle{fancy}
\renewcommand{\headrulewidth}{.4pt}
\renewcommand{\footrulewidth}{.4pt}
\fancyhead[RO]{\footnotesize\thepage}
\fancyhead[LO]{\footnotesize{\ifx\classlocal\undefined{}\else\itshape\classlocal{} -- {}\fi}\makeatletter\@title\makeatother}
\fancyfoot[RO]{\footnotesize\itshape\makeatletter\@author\makeatother}

\renewcommand{\maketitle}{
    \thispagestyle{plain}
    \begin{center}
        \ifx\instituteloc\undefined{}\else{\scshape\instituteloc}\\[10pt]\fi
        \hrule
        \vspace{10pt}
        {\LARGE\bfseries\@title}\\[5pt]
        \StudentLang: {\itshape\@author}
        \vspace{8pt}
        \hrule
        \vspace{10pt}
        \ifx\classlocal\undefined{}\else\CourseLang: {\itshape\classlocal{} \ifx\professorloc\undefined{}\else{-- }\fi}\fi
        \ifx\professorloc\undefined{}\else{\ProfessorLang: {\itshape\professorloc}}\fi
        \vspace{20pt}
    \end{center}
}

\newsavebox{\problembox}
\newenvironment{problem}{\begin{center}\begin{lrbox}{\problembox}\begin{minipage}{.98\textwidth}}{\end{minipage}\end{lrbox}\fbox{\usebox{\problembox}}\end{center}}

\endinput
