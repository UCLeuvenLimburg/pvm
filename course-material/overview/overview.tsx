import * as React from 'react';
import styled from 'styled-components';
import { TheoryEntry, LabEntry } from './entry';

export interface IProps
{
    className ?: string;
}

export interface IState { }


const Table = styled.table`
    margin: 1em auto;
    width: 40%;
`;

const Row = styled.tr`
`;

const HeaderRow = styled(Row)`
    background: black;
    color: white;
`;

const Header = styled.th`
    padding: 0.5em;
`;

const WeekHeader = styled(Header)`
    width: 5em;
`;

const Week = styled.td`
    text-align: center;
    background: black;
    color: white;
    font-size: 200%;
    font-weight: bold;
    user-select: none;
`;

export class Overview extends React.Component<IProps, IState>
{
    render()
    {
        // const me = this;

        return (
            <Table className={this.props.className}>
                <tbody>
                    <HeaderRow>
                        <WeekHeader>Week</WeekHeader>
                        <Header>Topic</Header>
                        <Header>Type</Header>
                    </HeaderRow>
                    {this.range(this.firstWeek, this.lastWeek + 1).map(i => this.renderWeek(i))}
                </tbody>
            </Table>
        );
    }

    private get firstWeek() : number { return 1; }

    private get lastWeek() : number { return 8; }

    private renderWeek(n : number) : JSX.Element
    {
        const rows = this.weekRows(n);

        const elts = this.range(0, rows.length).map(i => {
            if ( i === 0 )
            {
                return (
                    <Row>
                        <Week rowSpan={rows.length}>{n}</Week>
                        {rows[i]}
                    </Row>
                );
            }
            else
            {
                return (
                    <Row>
                        {rows[i]}
                    </Row>
                );
            }
        });

        return <React.Fragment>{elts}</React.Fragment>;
    }

    private weekRows(n : number) : JSX.Element[]
    {
        const weeks : JSX.Element[][] = [];

        weeks[1] = [
            theory('C++ Introduction', 'cpp-intro'),
            theory('Declarations'),
            lab('Declarations'),
            theory('Preprocessor'),
            lab('Preprocessor'),
        ];

        weeks[2] = [
            theory('Allocation Methods'),
            theory('Pointers'),
            lab('Pointers'),
        ];

        weeks[3] = [
            theory('Heap Allocation'),
            lab('Heap Allocation'),
            theory('Arrays'),
            lab('Arrays'),
            theory('Containers'),
        ];

        weeks[4] = [
            theory('Const'),
            lab('Types'),
            theory('References'),
            lab('References'),
        ];

        weeks[5] = [
            theory('Classes (overview)', 'classes-overview'),
            theory('Constructors'),
            theory('Structs'),
            theory('sizeof'),
            theory('Const Correctness'),
            lab('Types 2'),
            lab('Classes'),
        ];

        weeks[6] = [
            theory('Default Parameter Values'),
            lab('Default Parameter Values'),
            theory('Operator Overloading'),
            lab('Operator Overloading'),
            theory('RAII'),
            theory('Smart Pointers'),
            lab('Smart Pointers'),
        ];

        weeks[7] = [
            theory('Inheritance'),
            lab('Inheritance'),
            theory('Templates'),
            lab('Templates'),
            theory('Casting', 'casts'),
            lab('Casting', 'casts'),
        ];

        weeks[8] = [
            theory('Performance (optional)', 'performance'),
            lab('Performance (optional)', 'performance'),
            theory('Bit Manipulation'),
            theory('Technical Details'),
        ];

        return weeks[n];


        function theory(caption : string, filename : string | null = null) : JSX.Element
        {
            if ( filename === null )
            {
                filename = caption.toLowerCase().replace(' ', '-');
            }

            const url = `topics/${filename}.pdf`;

            return <TheoryEntry caption={caption} url={url} />
        }

        function lab(caption : string, directoryName : string | null = null) : JSX.Element
        {
            if ( directoryName === null )
            {
                directoryName = caption.toLowerCase();
            }

            const url = `labs/${directoryName}/index.html`;

            return <LabEntry caption={caption} url={url} />
        }
    }

    private range(a : number, b : number) : number[]
    {
        return a < b ? [ a, ...this.range(a + 1, b) ] : [];
    }
}
