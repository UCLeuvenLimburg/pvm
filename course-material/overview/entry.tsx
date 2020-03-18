import * as React from 'react';
import styled from 'styled-components';


export interface IProps
{
    className ?: string;
    url : string;
    caption : string;
}

export interface IState { }

const theoryColor = '#AAF';
const labColor = '#FAA';

const TagTd = styled.td`
    width: 8em;
    text-align: center;
    font-variant: small-caps;
`;

const TheoryTag = styled(TagTd)`
    background: ${_ => theoryColor};
`;

const LabTag = styled(TagTd)`
    background: ${_ => labColor}
`;

const Td = styled.td`
    padding: 0.5em;
    text-align: center;
`;

const TheoryTd = styled(Td)`
    background: ${_ => theoryColor};
`;

const LabTd = styled(Td)`
    background: ${_ => labColor};
`;

export abstract class Entry extends React.Component<IProps, IState>
{
    render()
    {
        return (
            <React.Fragment>
                {this.renderCaption()}
                {this.renderTag()}
            </React.Fragment>
        );
    }

    abstract renderCaption() : JSX.Element;

    abstract renderTag() : JSX.Element;
}

export class TheoryEntry extends Entry
{
    renderCaption()
    {
        return (
            <TheoryTd>
                <a href={this.props.url}>{this.props.caption}</a>
            </TheoryTd>
        );
    }

    renderTag()
    {
        return (
            <TheoryTag>
                Theory
            </TheoryTag>
        );
    }
}

export class LabEntry extends Entry
{
    renderCaption()
    {
        return (
            <LabTd>
                <a href={this.props.url}>{this.props.caption}</a>
            </LabTd>
        );
    }

    renderTag()
    {
        return (
            <LabTag>
                Exercise
            </LabTag>
        );
    }
}