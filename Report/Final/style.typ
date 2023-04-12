#let template(doc) = [

    #set text(
    font: "Time News Roman",
    size: 14pt,
    lang: "vi",
    )

    #set page(
    paper: "a4",
    numbering: "1",
    margin: (top: 3cm, bottom: 2.5cm, left: 3cm, right: 2cm)
    )

    #set par(
        linebreaks: "optimized",
        justify: true,
        leading: 1em,
        first-line-indent: 1.5em,
    )
    #show par: set block(spacing: 1.6em)

    #set heading(
    numbering: "1.1."
    )

    #show heading.where(level: 1, numbering: "1.1."): it => [
        #pad(
            top: 1.5em,
            bottom: 1.5em,
        )[
            #text(size: 20pt)[
                Chương #counter(heading).display() 
            ]
            #pad(top: 2pt)[
                #text(size: 24pt)[
                    #it.body
                ]
            ]
        ]
    ]

    #set figure(
        numbering: "1.1"
    )

    #set raw(
        lang: "cpp"
    )

    #set list(
        indent: 16pt,
        tight: false
    )

    #show "Interface" : strong
    #show "Usage" : strong
    #show "Parameters" : strong
    #show "Return" : strong

    #show raw.where(block: true): block.with(
    width: 100%,
    fill: luma(240),
    inset: 2pt,
    outset: (y: 3pt),
    radius: 2pt,
    breakable: false
    )

    #show raw.where(block: false): box.with(
    fill: luma(240),
    inset: (x: 3pt, y: 0pt),
    outset: (y: 3pt),
    radius: 2pt,
    )

    #doc
    
]